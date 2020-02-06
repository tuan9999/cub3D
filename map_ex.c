/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_ex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 12:05:25 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/05 13:52:04 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		freearr(void)
{
	ft_putstr_fd("Map error.", 1);
	exit(0);
}

int		malloc_map(t_raycaster *rc)
{
	int x;
	int w_y;

	x = rc->globals.mapheight;
	w_y = rc->globals.mapwidth;
	g_worldmap = (int **)malloc(sizeof(int *) * x + 1);
	if (!g_worldmap)
		return (-1);
	while (x != 0)
	{
		x--;
		g_worldmap[x] = (int *)malloc(sizeof(int) * w_y + 1);
		if (!g_worldmap[x])
			freearr();
	}
	g_worldmap[x] = (int *)malloc(sizeof(int) * w_y + 1);
	if (!g_worldmap[x])
		freearr();
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
