/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 13:22:04 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/05 12:52:19 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				handle_events(int keycode, t_raycaster *rc)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(rc->mlx_ptr, rc->mlx_window);
		exit(0);
	}
	if (keycode == K_W)
		rc->globals.movingforward = 1;
	if (keycode == K_S)
		rc->globals.movingback = 1;
	if (keycode == K_D)
		rc->globals.movingright = 1;
	if (keycode == K_A)
		rc->globals.movingleft = 1;
	if (keycode == K_RIGHT)
		rc->globals.straferight = 1;
	if (keycode == K_LEFT)
		rc->globals.strafeleft = 1;
	return (0);
}

int				handle_release(int keycode, t_raycaster *rc)
{
	if (keycode == K_W)
		rc->globals.movingforward = 0;
	if (keycode == K_S)
		rc->globals.movingback = 0;
	if (keycode == K_D)
		rc->globals.movingright = 0;
	if (keycode == K_A)
		rc->globals.movingleft = 0;
	if (keycode == K_RIGHT)
		rc->globals.straferight = 0;
	if (keycode == K_LEFT)
		rc->globals.strafeleft = 0;
	return (0);
}

int				handle_strafe(t_raycaster *rc)
{
	float	rotate;
	double	old_dir_x;
	double	old_plane_x;

	if (rc->globals.straferight == 1)
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
	if (rc->globals.movingright == 1)
	{
		if (g_worldmap[(int)(rc->player_pos_x + rc->player_plane_x *
							0.5)][(int)(rc->player_pos_y)] == 0)
			rc->player_pos_x += rc->player_plane_x * MV_SPEED;
		if (g_worldmap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y +
										rc->player_plane_y * 0.5)] == 0)
			rc->player_pos_y += rc->player_plane_y * MV_SPEED;
	}
	if (rc->globals.movingleft == 1)
	{
		if (g_worldmap[(int)(rc->player_pos_x - rc->player_plane_x *
							0.5)][(int)(rc->player_pos_y)] == 0)
			rc->player_pos_x -= rc->player_plane_x * MV_SPEED;
		if (g_worldmap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y -
										rc->player_plane_y * 0.5)] == 0)
			rc->player_pos_y -= rc->player_plane_y * MV_SPEED;
	}
	return (0);
}

int				handle_moving(t_raycaster *rc)
{
	if (rc->globals.movingforward == 1)
	{
		if (g_worldmap[(int)(rc->player_pos_x + rc->player_dir_x *
							0.5)][(int)(rc->player_pos_y)] == 0)
			rc->player_pos_x += rc->player_dir_x * MV_SPEED;
		if (g_worldmap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y +
									rc->player_dir_y * 0.5)] == 0)
			rc->player_pos_y += rc->player_dir_y * MV_SPEED;
	}
	if (rc->globals.movingback == 1)
	{
		if (g_worldmap[(int)(rc->player_pos_x - rc->player_dir_x *
							0.5)][(int)(rc->player_pos_y)] == 0)
			rc->player_pos_x -= rc->player_dir_x * MV_SPEED;
		if (g_worldmap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y -
										rc->player_dir_y * 0.5)] == 0)
			rc->player_pos_y -= rc->player_dir_y * MV_SPEED;
	}
	if ((rc->globals.movingright == 1) || (rc->globals.movingleft == 1))
		handle_lrmove(rc);
	if ((rc->globals.straferight == 1) || (rc->globals.strafeleft == 1))
		handle_strafe(rc);
	return (0);
}
