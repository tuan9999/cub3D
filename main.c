/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 16:10:30 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/02 11:53:48 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				render_frame(t_raycaster *rc)
{
	int x;

	x = 0;
	if (g_movingback || g_movingforward || g_movingleft || g_movingright ||
		g_strafeleft || g_straferight)
		handle_moving(rc);
	mlx_put_image_to_window(rc->mlx_ptr, rc->mlx_window, rc->img_ptr, 0, 0);
	while (x < g_win_x)
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
	g_z_buffer = (double *)malloc(sizeof(double) * g_win_x);
	rc->img_ptr = mlx_new_image(rc->mlx_ptr, g_win_x, g_win_y);
	rc->addr = mlx_get_data_addr(rc->img_ptr, &(rc->bits_per_pixel),
								&(rc->line_length), &(rc->endian));
	get_texture_img(rc);
	mlx_loop_hook(rc->mlx_ptr, render_frame, rc);
	mlx_hook(rc->mlx_window, E_KEY_PRESS, 0, handle_events, rc);
	mlx_hook(rc->mlx_window, E_KEY_RELEASE, 0, handle_release, rc);
	mlx_loop(rc->mlx_ptr);
	return (0);
}

int				checker(char **argv, int (*funct_ptr[])())
{
	if (get_file(argv[1]) < 0)
		return (-1);
	if (check_valid(g_file, funct_ptr) < 0)
		return (-1);
	while (ft_isdigit(**g_file) != 1)
		g_file++;
	if (populate_map(g_file) < 0)
		return (-1);
	g_fl_color = convert_fc_color(g_floor_color.r, g_floor_color.g,
									g_floor_color.b);
	g_ce_color = convert_fc_color(g_ceiling_color.r, g_ceiling_color.g,
									g_ceiling_color.b);
	return (0);
}

int				main(int argc, char **argv)
{
	t_raycaster	rc;
	int			(*funct_ptr[8])(char *);

	funct_ptr[0] = &get_resolution;
	funct_ptr[1] = &get_path_north;
	funct_ptr[2] = &get_path_south;
	funct_ptr[3] = &get_path_west;
	funct_ptr[4] = &get_path_east;
	funct_ptr[5] = &get_path_sprite;
	funct_ptr[6] = &get_floor_color;
	funct_ptr[7] = &get_ceiling_color;
	if (checker(argv, funct_ptr) < 0)
		return (-1);
	if (argv[2] && bmp_init(&rc) == 0)
	{
		bmp_creator(&rc);
		exit(0);
	}
	if (init(&rc) != 0 || error_check(argv, argc) != 0)
		return (-1);
	if (argc)
		cub3d(&rc);
	mlx_destroy_window(rc.mlx_ptr, rc.mlx_window);
	exit(0);
}
