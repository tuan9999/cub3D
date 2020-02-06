/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 11:44:33 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/05 16:01:19 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int		ft_put_sprite(t_raycaster *rc, unsigned int color, int y)
{
	int d;
	int pos;

	d = (y) * 256 - rc->globals.win_y * 128 + rc->sprite.sprite_height * 128;
	rc->sprite.text_y = ((d * rc->sprite.height) /
							rc->sprite.sprite_height) / 256;
	pos = ((rc->sprite.text_y * rc->sprite.line_length) +
			(rc->sprite.text_x * (rc->sprite.bits_per_pixel / 8)));
	color = *((unsigned int *)(rc->sprite.addr + pos));
	return (color);
}

void				sprite_draw_calc(t_raycaster *rc)
{
	if (rc->sprite.draw_start_y < 0)
		rc->sprite.draw_start_y = 0;
	rc->sprite.draw_end_y = rc->sprite.sprite_height / 2 +
							rc->globals.win_y / 2;
	if (rc->sprite.draw_end_y >= rc->globals.win_y)
		rc->sprite.draw_end_y = rc->globals.win_y - 1;
	rc->sprite.sprite_width = fabs((rc->globals.win_y /
								(rc->sprite.transform_y)));
	rc->sprite.draw_start_x = -rc->sprite.sprite_width / 2 +
								rc->sprite.sprite_screen_x;
	if (rc->sprite.draw_start_x < 0)
		rc->sprite.draw_start_x = 0;
	rc->sprite.draw_end_x = rc->sprite.sprite_width / 2 +
							rc->sprite.sprite_screen_x;
	if (rc->sprite.draw_end_x >= rc->globals.win_x)
		rc->sprite.draw_end_x = rc->globals.win_x - 1;
	rc->sprite.stripe = rc->sprite.draw_start_x;
}

void				sprite_calc(t_raycaster *rc, int sprite_order[], int i)
{
	rc->sprite.sprite_x = g_sprite_list[sprite_order[i]].x -
							rc->player_pos_x;
	rc->sprite.sprite_y = g_sprite_list[sprite_order[i]].y -
							rc->player_pos_y;
	rc->sprite.inv_det = 1.0 / (rc->player_plane_x *
	rc->player_dir_y - rc->player_dir_x * rc->player_plane_y);
	rc->sprite.transform_x = rc->sprite.inv_det *
	(rc->player_dir_y * rc->sprite.sprite_x -
	rc->player_dir_x * rc->sprite.sprite_y);
	rc->sprite.transform_y = rc->sprite.inv_det *
	(-rc->player_plane_y * rc->sprite.sprite_x +
	rc->player_plane_x * rc->sprite.sprite_y);
	rc->sprite.sprite_screen_x = ((rc->globals.win_x / 2) *
	(1 + rc->sprite.transform_x / rc->sprite.transform_y));
	rc->sprite.sprite_height = fabs((rc->globals.win_y /
								(rc->sprite.transform_y)));
	rc->sprite.draw_start_y = -rc->sprite.sprite_height / 2 +
								rc->globals.win_y / 2;
	sprite_draw_calc(rc);
}

int					sprite_cast_ex(t_raycaster *rc, int y)
{
	rc->sprite.text_x = (256 * (rc->sprite.stripe -
	(-rc->sprite.sprite_width / 2 + rc->sprite.sprite_screen_x))
	* rc->sprite.width / rc->sprite.sprite_width) / 256;
	if (rc->sprite.transform_y > 0 && rc->sprite.stripe > 0 &&
	rc->sprite.stripe < rc->globals.win_x && rc->sprite.transform_y <
								g_z_buffer[rc->sprite.stripe])
	{
		y = rc->sprite.draw_start_y;
		while (y < rc->sprite.draw_end_y)
		{
			g_color = ft_put_sprite(rc, g_color, y);
			if ((g_color & 0x00FFFFFF) != 0)
				ft_put_pixel(rc, g_color, y, rc->sprite.stripe);
			y++;
		}
	}
	rc->sprite.stripe++;
	return (rc->sprite.stripe);
}

void				sprite_cast(t_raycaster *rc)
{
	int		i;
	int		y;
	int		sprite_order[g_num_sprite];
	double	sprite_dist[g_num_sprite];

	i = 0;
	y = 0;
	while (i < g_num_sprite)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((rc->player_pos_x - g_sprite_list[i].x) *
		(rc->player_pos_x - g_sprite_list[i].x) + (rc->player_pos_y -
		g_sprite_list[i].y) * (rc->player_pos_y - g_sprite_list[i].y));
		i++;
	}
	comb_sort(sprite_order, sprite_dist, g_num_sprite);
	i = 0;
	while (i < g_num_sprite)
	{
		sprite_calc(rc, sprite_order, i);
		while (rc->sprite.stripe < rc->sprite.draw_end_x)
			rc->sprite.stripe = sprite_cast_ex(rc, y);
		i++;
	}
}
