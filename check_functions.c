/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 11:55:16 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/08 10:32:47 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_resolution(char *file, t_raycaster *rc)
{
	file++;
	while (ft_isdigit(*file) != 1)
	{
		if (!ft_strchr("R 0123456789", *file) || *file == '-')
		{
			ft_putstr_fd("invalid resoultion", 1);
			exit(0);
		}
		file++;
	}
	rc->globals.win_x = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
		file++;
	while (ft_isdigit(*file) != 1)
	{
		if (!ft_strchr("R 0123456789", *file) || *file == '-')
		{
			ft_putstr_fd("invalid resoultion", 1);
			exit(0);
		}
		file++;
	}
	rc->globals.win_y = ft_atoi(file);
	return (0);
}

int			check_valid(char **file, t_raycaster *rc)
{
	int		x;
	int		i;
	char	*set;

	x = 0;
	i = 0;
	set = "RNSWESFC";
	while (file[x] && ft_isdigit(file[x][0]) != 1)
	{
		while (file[x][0] == '\0' || file[x][0] == ' ')
			x++;
		if (ft_strchr(set, file[x][0]) == NULL && ft_isdigit(file[x][0]) != 1)
		{
			ft_putstr_fd("invalid file.\n", 1);
			exit(0);
		}
		else if (ft_isdigit(file[x][0]) == 1)
			return (0);
		else
			assign_paths(file[x], rc);
		x++;
		i++;
	}
	return (0);
}

int			get_floor_color(char *file, t_raycaster *rc)
{
	file++;
	while (ft_isdigit(*file) != 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	rc->globals.floor_color.r = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	file++;
	rc->globals.floor_color.g = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	file++;
	rc->globals.floor_color.b = ft_atoi(file);
	return (0);
}

int			get_ceiling_color(char *file, t_raycaster *rc)
{
	file++;
	while (ft_isdigit(*file) != 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	rc->globals.ceiling_color.r = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	file++;
	rc->globals.ceiling_color.g = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	file++;
	rc->globals.ceiling_color.b = ft_atoi(file);
	return (0);
}
