/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_ex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 12:05:25 by tuperera       #+#    #+#                */
/*   Updated: 2020/01/20 12:06:44 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		freearr(int count)
{
	while (count >= 0)
	{
		if (g_worldmap[count])
			free(g_worldmap[count]);
		count--;
	}
	if (g_worldmap)
		free(g_worldmap);
	return (-1);
}

int		malloc_map(void)
{
	int x;
	int w_y;

	x = g_mapheight;
	w_y = g_mapwidth;
	g_worldmap = (int **)malloc(sizeof(int *) * x + 1);
	if (!g_worldmap)
		return (-1);
	while (x != 0)
	{
		x--;
		g_worldmap[x] = (int *)malloc(sizeof(int) * w_y + 1);
		if (!g_worldmap[x])
			return (freearr(x));
	}
	g_worldmap[x] = (int *)malloc(sizeof(int) * w_y + 1);
	if (!g_worldmap[x])
		return (freearr(x));
	return (0);
}

int		populate_sprite(char **file)
{
	int		x;
	int		y;
	int		sprite_num;

	x = 0;
	g_sprite_list = malloc(sizeof(t_sprite_list) * g_num_sprite);
	sprite_num = 0;
	while (file[x][0] && sprite_num < g_num_sprite)
	{
		y = 0;
		while (file[x][y] && sprite_num < g_num_sprite)
		{
			if (ft_isdigit(file[x][y]) == 1)
				if (file[x][y] == '2')
				{
					g_sprite_list[sprite_num].x = x;
					g_sprite_list[sprite_num].y = y;
					sprite_num++;
				}
			y++;
		}
		x++;
	}
	return (0);
}
