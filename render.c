/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 14:16:05 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/05 12:48:16 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_put_pixel(t_raycaster *rc, unsigned int color, int y, int x)
{
	int	pos;

	pos = ((y * rc->line_length) + (x * (rc->bits_per_pixel / 8)));
	*((unsigned int *)(rc->addr + pos)) = color;
}

void			get_text_color(t_raycaster *rc, int y)
{
	if (rc->side == 1 && rc->ray_dir_y > 0)
		g_color = ft_put_text_east(rc, g_color, y);
	else if (rc->side == 1 && rc->ray_dir_y < 0)
		g_color = ft_put_text_west(rc, g_color, y);
	else if (rc->side == 0 && rc->ray_dir_x > 0)
		g_color = ft_put_text_south(rc, g_color, y);
	else
		g_color = ft_put_text(rc, g_color, y);
}

void			draw_vert_line(t_raycaster *rc, int x)
{
	int	y;

	y = 0;
	while (y <= rc->draw_start)
	{
		ft_put_pixel(rc, rc->globals.ce_color, y, x);
		y++;
	}
	while (y <= rc->draw_end)
	{
		get_text_color(rc, y);
		ft_put_pixel(rc, g_color, y, x);
		y++;
	}
	while (y < rc->globals.win_y)
	{
		ft_put_pixel(rc, rc->globals.fl_color, y, x);
		y++;
	}
}
