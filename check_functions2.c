/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_functions2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 13:19:25 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/06 15:36:22 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_path_north(char *file, t_raycaster *rc)
{
	while (ft_strchr("NO .\t", *file) != NULL)
	{
		if (ft_strchr(".", *file))
		{
			file = ft_strchr(file, '.');
			if (ft_strchr(file, ' '))
				break ;
			rc->globals.north_text = (char *)ft_calloc((ft_strlen(file) + 1),
													sizeof(char));
			ft_strlcpy(rc->globals.north_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}

int			get_path_south(char *file, t_raycaster *rc)
{
	while (ft_strchr("SO .\t", *file) != NULL)
	{
		if (ft_strchr(".", *file))
		{
			file = ft_strchr(file, '.');
			if (ft_strchr(file, ' '))
				break ;
			rc->globals.south_text = (char *)ft_calloc((ft_strlen(file) + 1),
													sizeof(char));
			ft_strlcpy(rc->globals.south_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}

int			get_path_west(char *file, t_raycaster *rc)
{
	while (ft_strchr("WE .\t", *file) != NULL)
	{
		if (ft_strchr(".", *file))
		{
			file = ft_strchr(file, '.');
			if (ft_strchr(file, ' '))
				break ;
			rc->globals.west_text = (char *)ft_calloc((ft_strlen(file) + 1),
													sizeof(char));
			ft_strlcpy(rc->globals.west_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}

int			get_path_east(char *file, t_raycaster *rc)
{
	while (ft_strchr("EA .\t", *file) != NULL)
	{
		if (ft_strchr(".", *file))
		{
			file = ft_strchr(file, '.');
			if (ft_strchr(file, ' '))
				break ;
			rc->globals.east_text = (char *)ft_calloc((ft_strlen(file) + 1),
													sizeof(char));
			ft_strlcpy(rc->globals.east_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}

int			get_path_sprite(char *file, t_raycaster *rc)
{
	while (ft_strchr("S .\t", *file) != NULL)
	{
		if (ft_strchr(".", *file))
		{
			file = ft_strchr(file, '.');
			if (ft_strchr(file, ' '))
				break ;
			rc->globals.sprite_text = (char *)ft_calloc((ft_strlen(file) + 1),
													sizeof(char));
			ft_strlcpy(rc->globals.sprite_text, file, ft_strlen(file) + 1);
			return (0);
		}
		file++;
	}
	ft_putstr_fd("invalid texture.\n", 1);
	return (-1);
}
