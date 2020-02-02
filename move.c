/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 13:22:04 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/02 11:08:41 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				handle_events(int keycode, t_raycaster *rc)
{
	if (keycode == K_ESC || keycode == E_EXIT)
	{
		mlx_destroy_window(rc->mlx_ptr, rc->mlx_window);
		exit(0);
	}
	if (keycode == K_W)
		g_movingforward = 1;
	if (keycode == K_S)
		g_movingback = 1;
	if (keycode == K_D)
		g_movingright = 1;
	if (keycode == K_A)
		g_movingleft = 1;
	if (keycode == K_RIGHT)
		g_straferight = 1;
	if (keycode == K_LEFT)
		g_strafeleft = 1;
	return (0);
}

int				handle_release(int keycode)
{
	if (keycode == K_W)
		g_movingforward = 0;
	if (keycode == K_S)
		g_movingback = 0;
	if (keycode == K_D)
		g_movingright = 0;
	if (keycode == K_A)
		g_movingleft = 0;
	if (keycode == K_RIGHT)
		g_straferight = 0;
	if (keycode == K_LEFT)
		g_strafeleft = 0;
	return (0);
}

int				handle_strafe(t_raycaster *rc)
{
	float	rotate;
	double	old_dir_x;
	double	old_plane_x;

	if (g_straferight == 1)
		rotate = -ROT_SPEED;
	else
		rotate = ROT_SPEED;
	old_dir_x = rc->player_dir_x;
	rc->player_dir_x = rc->player_dir_x * cos(rotate) -
							rc->player_dir_y * sin(rotate);
	rc->player_dir_y = old_dir_x * sin(rotate) +
							rc->player_dir_y * cos(rotate);
	old_plane_x = rc->player_plane_x;
	rc->player_plane_x = rc->player_plane_x * cos(rotate) -
							rc->player_plane_y * sin(rotate);
	rc->player_plane_y = old_plane_x * sin(rotate) +
							rc->player_plane_y * cos(rotate);
	return (0);
}

int				handle_lrmove(t_raycaster *rc)
{
	if (g_movingright == 1)
	{
		if (g_worldmap[(int)(rc->player_pos_x + rc->player_dir_x *
							MV_SPEED)][(int)(rc->player_pos_y)] == 0)
			rc->player_pos_x += rc->player_plane_x * MV_SPEED;
		if (g_worldmap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y +
										rc->player_dir_y * MV_SPEED)] == 0)
			rc->player_pos_y += rc->player_plane_y * MV_SPEED;
	}
	if (g_movingleft == 1)
	{
		if (g_worldmap[(int)(rc->player_pos_x + rc->player_dir_x *
							MV_SPEED)][(int)(rc->player_pos_y)] == 0)
			rc->player_pos_x -= rc->player_plane_x * MV_SPEED;
		if (g_worldmap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y +
										rc->player_dir_y * MV_SPEED)] == 0)
			rc->player_pos_y -= rc->player_plane_y * MV_SPEED;
	}
	return (0);
}

int				handle_moving(t_raycaster *rc)
{
	if (g_movingforward == 1)
	{
		if (g_worldmap[(int)(rc->player_pos_x + rc->player_dir_x *
							MV_SPEED)][(int)(rc->player_pos_y)] == 0)
			rc->player_pos_x += rc->player_dir_x * MV_SPEED;
		if (g_worldmap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y +
									rc->player_dir_y * MV_SPEED)] == 0)
			rc->player_pos_y += rc->player_dir_y * MV_SPEED;
	}
	if (g_movingback == 1)
	{
		if (g_worldmap[(int)(rc->player_pos_x - rc->player_dir_x *
							MV_SPEED)][(int)(rc->player_pos_y)] == 0)
			rc->player_pos_x -= rc->player_dir_x * MV_SPEED;
		if (g_worldmap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y -
										rc->player_dir_y * MV_SPEED)] == 0)
			rc->player_pos_y -= rc->player_dir_y * MV_SPEED;
	}
	if ((g_movingright == 1) || (g_movingleft == 1))
		handle_lrmove(rc);
	if ((g_straferight == 1) || (g_strafeleft == 1))
		handle_strafe(rc);
	return (0);
}
