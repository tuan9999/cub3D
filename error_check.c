/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 14:58:31 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/06 14:38:06 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		file_exist(const char *fname)
{
	int fd;

	fd = open(fname, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

void	color_valid(t_raycaster *rc)
{
	if (rc->globals.ceiling_color.b > 255 || rc->globals.ceiling_color.b < 0
	|| rc->globals.floor_color.b > 255 || rc->globals.floor_color.b < 0)
	{
		ft_putstr_fd("Invalid color", 1);
		exit(0);
	}
	else if (rc->globals.ceiling_color.g > 255 ||
	rc->globals.ceiling_color.g < 0 || rc->globals.floor_color.g > 255 ||
	rc->globals.floor_color.g < 0)
	{
		ft_putstr_fd("Invalid color", 1);
		exit(0);
	}
	else if (rc->globals.ceiling_color.r > 255 ||
	rc->globals.ceiling_color.r < 0 || rc->globals.floor_color.r > 255 ||
	rc->globals.floor_color.r < 0)
	{
		ft_putstr_fd("Invalid color", 1);
		exit(0);
	}
}

void	check_cub_file(char *arg)
{
	while (*arg != '.')
		arg++;
	if (ft_strncmp(arg, ".cub", 5) != 0)
	{
		ft_putstr_fd("invalid cub file\n", 1);
		exit(0);
	}
}

void	check_file_paths(t_raycaster *rc)
{
	if ((file_exist(rc->globals.west_text) == 0) ||
		(file_exist(rc->globals.east_text) == 0) ||
		(file_exist(rc->globals.south_text) == 0) ||
		(file_exist(rc->globals.north_text) == 0) ||
		(file_exist(rc->globals.sprite_text) == 0))
	{
		ft_putstr_fd("Invalid file path", 1);
		exit(0);
	}
}

int		error_check(char **args, int argc, t_raycaster *rc)
{
	if (rc->globals.win_x > 2560 || rc->globals.win_y > 1440)
	{
		if (rc->globals.win_x > 2560)
			rc->globals.win_x = 2560;
		if (rc->globals.win_y > 1440)
			rc->globals.win_y = 1440;
		ft_putstr_fd("Invalid resolution, resolution resized", 1);
	}
	else if (argc > 3 || argc < 2)
	{
		ft_putstr_fd("Invalid arguments", 1);
		exit(0);
	}
	else if (argc == 3 && ft_strncmp(args[2], "--save", 6) != 0)
	{
		ft_putstr_fd("Invalid second argument", 1);
		exit(0);
	}
	else
		check_file_paths(rc);
	color_valid(rc);
	check_cub_file(args[1]);
	return (0);
}
