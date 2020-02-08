/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:10:30 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/08 10:26:33 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				render_frame(t_raycaster *rc)
{
	int x;

	x = 0;
	if (rc->globals.movingback || rc->globals.movingforward ||
		rc->globals.movingleft || rc->globals.movingright ||
		rc->globals.strafeleft || rc->globals.straferight)
		handle_moving(rc);
	mlx_put_image_to_window(rc->mlx_ptr, rc->mlx_window, rc->img_ptr, 0, 0);
	while (x < rc->globals.win_x)
	{
		initial_calc(rc, x);
		perform_dda(rc);
		calc_wall_height(rc);
		calculatetext(rc);
		calculatetextsouth(rc);
		calculatetexteast(rc);
		calculatetextwest(rc);
		g_z_buffer[x] = rc->perp_wall_dist;
		draw_vert_line(rc, x);
		x++;
	}
	sprite_cast(rc);
	mlx_put_image_to_window(rc->mlx_ptr, rc->mlx_window, rc->img_ptr, 0, 0);
	return (0);
}

int				cub3d(t_raycaster *rc)
{
	g_z_buffer = (double *)malloc(sizeof(double) * rc->globals.win_x);
	rc->img_ptr = mlx_new_image(rc->mlx_ptr, rc->globals.win_x,
								rc->globals.win_y);
	rc->addr = mlx_get_data_addr(rc->img_ptr, &(rc->bits_per_pixel),
								&(rc->line_length), &(rc->endian));
	get_texture_img(rc);
	mlx_loop_hook(rc->mlx_ptr, render_frame, rc);
	mlx_hook(rc->mlx_window, E_KEY_PRESS, (1L << 0), handle_events, rc);
	mlx_hook(rc->mlx_window, E_KEY_RELEASE, (1L << 1), handle_release, rc);
	mlx_hook(rc->mlx_window, E_EXIT, 0, ft_exit_prgm, NULL);
	mlx_loop(rc->mlx_ptr);
	return (0);
}

int				checker(char **argv, t_raycaster *rc)
{
	if (get_file(argv[1], rc) < 0)
		exit(0);
	if (check_valid(rc->globals.file, rc) < 0)
		exit(0);
	while (ft_isdigit(**(rc->globals.file)) != 1)
		rc->globals.file++;
	populate_map(rc->globals.file, rc);
	rc->globals.fl_color = convert_fc_color(rc->globals.floor_color.r,
						rc->globals.floor_color.g, rc->globals.floor_color.b);
	rc->globals.ce_color = convert_fc_color(rc->globals.ceiling_color.r,
					rc->globals.ceiling_color.g, rc->globals.ceiling_color.b);
	return (0);
}

void			init_struct(t_raycaster *rc)
{
	rc->globals.movingforward = 0;
	rc->globals.movingback = 0;
	rc->globals.movingleft = 0;
	rc->globals.movingright = 0;
	rc->globals.strafeleft = 0;
	rc->globals.straferight = 0;
	rc->map_x = 0;
	rc->map_y = 0;
	rc->globals.north_text = NULL;
	rc->globals.south_text = NULL;
	rc->globals.east_text = NULL;
	rc->globals.west_text = NULL;
	rc->globals.sprite_text = NULL;
	rc->globals.direction = '\0';
	rc->globals.win_x = 0;
	rc->globals.win_y = 0;
	rc->globals.floor_color.r = -1;
	rc->globals.floor_color.g = -1;
	rc->globals.floor_color.b = -1;
	rc->globals.ceiling_color.r = -1;
	rc->globals.ceiling_color.g = -1;
	rc->globals.ceiling_color.b = -1;
}

int				main(int argc, char **argv)
{
	t_raycaster	rc;

	init_struct(&rc);
	if (argc < 2)
	{
		ft_putstr_fd("No file given.\n", 1);
		exit(0);
	}
	if (checker(argv, &rc) < 0)
		return (-1);
	if (argv[2] && error_check(argv, argc, &rc) == 0 && bmp_init(&rc) == 0)
	{
		bmp_creator(&rc);
		exit(0);
	}
	if (error_check(argv, argc, &rc) != 0 || init(&rc) != 0)
		return (-1);
	if (argc)
		cub3d(&rc);
	mlx_destroy_window(rc.mlx_ptr, rc.mlx_window);
	exit(0);
}
