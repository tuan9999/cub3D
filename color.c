/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 14:13:25 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/05 12:04:10 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int		convert_fc_color(int r, int g, int b)
{
	unsigned int fc_color;

	fc_color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (fc_color);
}

unsigned int		select_wall_color(int map_x, int map_y)
{
	if (g_worldmap[map_x][map_y] == 1)
		g_color = BLUE;
	else if (g_worldmap[map_x][map_y] == 2)
		g_color = GREEN;
	else
		g_color = WHITE;
	return (g_color);
}

void				comb_sort_ex(int *order, double *dist,
									t_sort *sort)
{
	if (dist[sort->i] > dist[sort->j])
	{
		sort->tempdist = dist[sort->i];
		dist[sort->i] = dist[sort->j];
		dist[sort->j] = sort->tempdist;
		sort->tempord = order[sort->i];
		order[sort->i] = order[sort->j];
		order[sort->j] = sort->tempord;
	}
}

void				comb_sort(int *order, double *dist, int amount)
{
	t_sort	sort;

	sort.i = 0;
	while (sort.i < amount)
	{
		sort.j = 0;
		while (sort.j < amount)
		{
			comb_sort_ex(order, dist, &sort);
			sort.j++;
		}
		sort.i++;
	}
}
