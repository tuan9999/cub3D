/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 13:05:56 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/05 17:35:31 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(char **file, t_raycaster *rc)
{
	int		x;
	int		y;
	int		ycheck;
	char	*set;

	set = "012NSEW";
	x = 0;
	ycheck = 0;
	while (file[x] && file[x][0] != '\0')
	{
		y = 0;
		while (file[x][y] && ft_strchr(set, file[x][y]))
			y++;
		if ((x != 0 && ycheck != y) || ft_strchr(set, file[x][y]) == NULL ||
		(file[x][0] == '\0' && file[x + 1][0] == '1' && file[x - 1][0] == '1'))
		{
			ft_putstr_fd("invalid map\n", 1);
			exit(0);
		}
		ycheck = y;
		x++;
	}
	rc->globals.mapwidth = y;
	rc->globals.mapheight = x;
	return (0);
}

int		pop_map_ex(int w_y, int x, int y, t_raycaster *rc)
{
	char *set;

	set = "NSEW";
	if (ft_strchr(set, rc->globals.file[x][y]))
	{
		rc->globals.direction = rc->globals.file[x][y];
		g_worldmap[x][w_y] = 0;
		rc->player_pos_x = x;
		rc->player_pos_y = w_y;
	}
	else if (rc->globals.file[x][y] == '2')
	{
		g_num_sprite++;
		g_worldmap[x][w_y] = 0;
	}
	else
		g_worldmap[x][w_y] = rc->globals.file[x][y] - '0';
	w_y++;
	return (w_y);
}

void	check_closed_map(int x, int y)
{
	int cx;
	int cy;

	cx = 0;
	x--;
	y--;
	while (cx != x)
	{
		cy = 0;
		if (g_worldmap[cx][0] != 1 || g_worldmap[cx][y] != 1)
		{
			ft_putstr_fd("invalid map\n", 1);
			exit(0);
		}
		while (cy != y)
		{
			if (g_worldmap[0][cy] != 1 || g_worldmap[x][cy] != 1)
			{
				ft_putstr_fd("invalid map\n", 1);
				exit(0);
			}
			cy++;
		}
		cx++;
	}
}

int		check_map_start_pos(char **file)
{
	int		x;
	int		y;
	int		check;

	check = 0;
	x = 0;
	while (file[x] && file[x][0] != '\0')
	{
		y = 0;
		while (file[x][y] && (ft_strchr("012", file[x][y]) ||
			ft_strchr("NSEW", file[x][y])))
		{
			if (ft_strchr("NSEW", file[x][y]) && check == 1)
				freearr();
			if (ft_strchr("NSEW", file[x][y]))
				check = 1;
			y++;
		}
		x++;
	}
	if (check == 0)
		freearr();
	return (0);
}

void	populate_map(char **file, t_raycaster *rc)
{
	int		x;
	int		y;
	int		w_y;

	if ((check_map(file, rc) < 0) || (malloc_map(rc) < 0) ||
		check_map_start_pos(file) < 0)
		exit(0);
	x = 0;
	g_num_sprite = 0;
	while (file[x][0])
	{
		w_y = 0;
		y = 0;
		while (file[x][y])
		{
			if (ft_strchr("012NSEW", file[x][y]))
				w_y = pop_map_ex(w_y, x, y, rc);
			y++;
		}
		x++;
	}
	if (g_num_sprite > 0)
		populate_sprite(file);
	check_closed_map(x, y);
}
