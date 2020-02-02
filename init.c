/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 17:42:10 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/02 11:52:27 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			change_dir(t_raycaster *rc)
{
	double		old_dir_x;
	double		old_plane_x;
	double		rotate;

	if (g_direction == 'S')
		rotate = M_PI;
	if (g_direction == 'E')
		rotate = 0.5 * M_PI;
	if (g_direction == 'W')
		rotate = 1.5 * M_PI;
	old_dir_x = rc->player_dir_x;
	rc->player_dir_x = rc->player_dir_x * cos(rotate) -
						rc->player_dir_y * sin(rotate);
	rc->player_dir_y = old_dir_x * sin(rotate) + rc->player_dir_y * cos(rotate);
	old_plane_x = rc->player_plane_x;
	rc->player_plane_x = rc->player_plane_x * cos(rotate) -
							rc->player_plane_y * sin(rotate);
	rc->player_plane_y = old_plane_x * sin(rotate) +
							rc->player_plane_y * cos(rotate);
}

int				init(t_raycaster *rc)
{
	rc->player_pos_x = g_play_pos_x;
	rc->player_pos_y = g_play_pos_y;
	rc->player_dir_x = INIT_P_DIR_X;
	rc->player_dir_y = INIT_P_DIR_Y;
	rc->player_plane_x = INIT_P_PLANE_X;
	rc->player_plane_y = INIT_P_PLANE_Y;
	if (g_direction != 'N')
		change_dir(rc);
	rc->mlx_ptr = mlx_init();
	if (rc->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error occured.", 1);
		return (-1);
	}
	rc->mlx_window = mlx_new_window(rc->mlx_ptr, g_win_x, g_win_y, "cub3d");
	mlx_do_key_autorepeatoff(rc->mlx_ptr);
	if (rc->mlx_window == NULL)
	{
		ft_putstr_fd("Error occured.", 1);
		return (-1);
	}
	return (0);
}

int				bmp_init(t_raycaster *rc)
{
	rc->player_pos_x = g_play_pos_x;
	rc->player_pos_y = g_play_pos_y;
	rc->player_dir_x = INIT_P_DIR_X;
	rc->player_dir_y = INIT_P_DIR_Y;
	rc->player_plane_x = INIT_P_PLANE_X;
	rc->player_plane_y = INIT_P_PLANE_Y;
	if (g_direction != 'N')
		change_dir(rc);
	rc->mlx_ptr = mlx_init();
	if (rc->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error occured.", 1);
		return (-1);
	}
	return (0);
}
