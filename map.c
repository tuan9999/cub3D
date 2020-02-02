/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 13:05:56 by tuperera       #+#    #+#                */
/*   Updated: 2020/01/20 12:20:47 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(char **file)
{
	int		x;
	int		y;
	int		ycheck;
	char	*set;

	set = "NSEW";
	x = 0;
	ycheck = 0;
	while (file[x] && file[x][0] != '\0')
	{
		y = 0;
		while (file[x][y] && (ft_isdigit(file[x][y]) == 1 ||
								ft_strchr(set, file[x][y])))
			y++;
		if (x != 0 && ycheck != y)
		{
			ft_putstr_fd("invalid map\n", 1);
			return (-1);
		}
		ycheck = y;
		x++;
	}
	g_mapwidth = y;
	g_mapheight = x;
	return (0);
}

int		pop_map_ex(char **file, int w_y, int x, int y)
{
	char *set;

	set = "NSEW";
	if (ft_strchr(set, file[x][y]))
	{
		g_direction = file[x][y];
		g_worldmap[x][w_y] = 0;
		g_play_pos_x = x;
		g_play_pos_y = w_y;
	}
	else if (file[x][y] == '2')
	{
		g_num_sprite++;
		g_worldmap[x][w_y] = 0;
	}
	else
		g_worldmap[x][w_y] = file[x][y] - '0';
	w_y++;
	return (w_y);
}

int		populate_map(char **file)
{
	int		x;
	int		y;
	int		w_y;
	char	*set;

	set = "NSEW";
	if ((check_map(file) < 0) || (malloc_map() < 0))
		return (-1);
	x = 0;
	g_num_sprite = 0;
	while (file[x][0])
	{
		w_y = 0;
		y = 0;
		while (file[x][y])
		{
			if (ft_isdigit(file[x][y]) == 1 || ft_strchr(set, file[x][y]))
				w_y = pop_map_ex(file, w_y, x, y);
			y++;
		}
		x++;
	}
	if (g_num_sprite > 0)
		populate_sprite(file);
	return (0);
}
