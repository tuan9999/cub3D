/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 17:44:49 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/05 12:41:40 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			init_calc_exten(t_raycaster *rc)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (rc->player_pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - rc->player_pos_x) *
							rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (rc->player_pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - rc->player_pos_y) *
							rc->delta_dist_y;
	}
}

void			initial_calc(t_raycaster *rc, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)(rc->globals.win_x) - 1;
	rc->ray_dir_x = rc->player_dir_x + rc->player_plane_x * camera_x;
	rc->ray_dir_y = rc->player_dir_y + rc->player_plane_y * camera_x;
	rc->map_x = (int)(rc->player_pos_x);
	rc->map_y = (int)(rc->player_pos_y);
	rc->delta_dist_x = sqrt(1 + pow(rc->ray_dir_y, 2) / pow(rc->ray_dir_x, 2));
	rc->delta_dist_y = sqrt(1 + pow(rc->ray_dir_x, 2) / pow(rc->ray_dir_y, 2));
	init_calc_exten(rc);
}

void			perform_dda(t_raycaster *rc)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (g_worldmap[rc->map_x][rc->map_y] > 0)
			hit = 1;
	}
}

void			calc_wall_height(t_raycaster *rc)
{
	if (rc->side == 0)
		rc->perp_wall_dist = (rc->map_x - rc->player_pos_x +
								(1 - rc->step_x) / 2) / rc->ray_dir_x;
	else
		rc->perp_wall_dist = (rc->map_y - rc->player_pos_y +
								(1 - rc->step_y) / 2) / rc->ray_dir_y;
	rc->line_height = (int)(rc->globals.win_y / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + rc->globals.win_y / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + rc->globals.win_y / 2;
	if (rc->draw_end >= rc->globals.win_y)
		rc->draw_end = rc->globals.win_y - 1;
}
