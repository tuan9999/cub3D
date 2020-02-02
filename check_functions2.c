/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 13:19:25 by tuperera       #+#    #+#                */
/*   Updated: 2019/12/16 14:39:19 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_path_north(char *file)
{
	while (ft_strchr(file, '.') != NULL)
	{
		if (ft_strchr(file, '.'))
		{
			file = ft_strchr(file, '.');
			g_north_text = (char *)calloc((ft_strlen(file) + 1), sizeof(char));
			ft_strlcpy(g_north_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}

int			get_path_south(char *file)
{
	while (ft_strchr(file, '.') != NULL)
	{
		if (ft_strchr(file, '.'))
		{
			file = ft_strchr(file, '.');
			g_south_text = (char *)calloc((ft_strlen(file) + 1), sizeof(char));
			ft_strlcpy(g_south_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}

int			get_path_west(char *file)
{
	while (ft_strchr(file, '.') != NULL)
	{
		if (ft_strchr(file, '.'))
		{
			file = ft_strchr(file, '.');
			g_west_text = (char *)calloc((ft_strlen(file) + 1), sizeof(char));
			ft_strlcpy(g_west_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}

int			get_path_east(char *file)
{
	while (ft_strchr(file, '.') != NULL)
	{
		if (ft_strchr(file, '.'))
		{
			file = ft_strchr(file, '.');
			g_east_text = (char *)calloc((ft_strlen(file) + 1), sizeof(char));
			ft_strlcpy(g_east_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}

int			get_path_sprite(char *file)
{
	while (ft_strchr(file, '.') != NULL)
	{
		if (ft_strchr(file, '.'))
		{
			file = ft_strchr(file, '.');
			g_sprite_text = (char *)calloc((ft_strlen(file) + 1), sizeof(char));
			ft_strlcpy(g_sprite_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}
