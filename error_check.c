/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 14:58:31 by tuperera       #+#    #+#                */
/*   Updated: 2020/01/27 15:46:04 by tuperera      ########   odam.nl         */
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

void	color_valid(void)
{
	if (g_ceiling_color.b > 255 || g_ceiling_color.b < 0 ||
		g_floor_color.b > 255 || g_floor_color.b < 0)
	{
		ft_putstr_fd("Invalid color", 1);
		exit(0);
	}
	else if (g_ceiling_color.g > 255 || g_ceiling_color.g < 0 ||
			g_floor_color.g > 255 || g_floor_color.g < 0)
	{
		ft_putstr_fd("Invalid color", 1);
		exit(0);
	}
	else if (g_ceiling_color.r > 255 || g_ceiling_color.r < 0 ||
			g_floor_color.r > 255 || g_floor_color.r < 0)
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

int		error_check(char **args, int argc)
{
	if (g_win_x > 5120 || g_win_y > 2880)
	{
		ft_putstr_fd("Invalid resolution", 1);
		exit(0);
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
	else if ((file_exist(g_west_text) == 0) || (file_exist(g_east_text) == 0) ||
			(file_exist(g_south_text) == 0) || (file_exist(g_north_text) == 0)
			|| (file_exist(g_sprite_text) == 0))
	{
		ft_putstr_fd("Invalid file path", 1);
		exit(0);
	}
	color_valid();
	check_cub_file(args[1]);
	return (0);
}
