/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 11:55:16 by tuperera       #+#    #+#                */
/*   Updated: 2020/01/27 15:38:23 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_resolution(char *file)
{
	file++;
	while (ft_isdigit(*file) != 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
		{
			ft_putstr_fd("invalid resoultion", 1);
			exit(0);
		}
		file++;
	}
	g_win_x = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
		file++;
	while (ft_isdigit(*file) != 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
		{
			ft_putstr_fd("invalid resoultion", 1);
			exit(0);
		}
		file++;
	}
	g_win_y = ft_atoi(file);
	return (0);
}

int			check_valid(char **file, int (*funct_ptr[])())
{
	int		x;
	int		i;
	char	*set;

	x = 0;
	i = 0;
	set = "RNSWESFC";
	while (file[x] && ft_isdigit(file[x][0]) != 1 && set[i])
	{
		while (file[x][0] == ' ' || file[x][0] == '\0')
			x++;
		if (file[x][0] != set[i] && ft_isdigit(file[x][0]) != 1)
		{
			ft_putstr_fd("invalid file.\n", 1);
			return (-1);
		}
		else if (ft_isdigit(file[x][0]) == 1)
			return (0);
		else if ((funct_ptr[i])(file[x]) < 0)
			return (-1);
		x++;
		i++;
	}
	return (0);
}

int			get_floor_color(char *file)
{
	file++;
	while (ft_isdigit(*file) != 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	g_floor_color.r = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	file++;
	g_floor_color.g = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	file++;
	g_floor_color.b = ft_atoi(file);
	return (0);
}

int			get_ceiling_color(char *file)
{
	file++;
	while (ft_isdigit(*file) != 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	g_ceiling_color.r = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	file++;
	g_ceiling_color.g = ft_atoi(file);
	while (ft_isdigit(*file) == 1)
	{
		if (ft_isalpha(*file) == 1 || *file == '-')
			return (-1);
		file++;
	}
	file++;
	g_ceiling_color.b = ft_atoi(file);
	return (0);
}
