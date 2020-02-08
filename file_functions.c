/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 11:47:30 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/08 10:34:26 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				freefile(void)
{
	ft_putstr_fd("Error occured.", 1);
	exit(0);
}

void			gnl(char *line, int fd, t_raycaster *rc)
{
	int i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		rc->globals.file[i] = (char *)malloc((ft_strlen(line) + 1) *
			sizeof(char));
		if (!rc->globals.file[i])
			freefile();
		ft_strlcpy(rc->globals.file[i], line, (ft_strlen(line) + 1));
		free(line);
		i++;
	}
	rc->globals.file[i] = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
	if (!rc->globals.file[i])
		freefile();
	ft_strlcpy(rc->globals.file[i], line, (ft_strlen(line) + 1));
	free(line);
}

int				get_file(char *argv, t_raycaster *rc)
{
	char		*line;
	int			fd;
	int			i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 1;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	fd = open(argv, O_RDONLY);
	rc->globals.file = (char **)malloc(sizeof(char *) * i);
	if (!rc->globals.file || i < 9)
		freefile();
	gnl(line, fd, rc);
	rc->globals.filelen = i;
	close(fd);
	return (0);
}

int				check_double(char *str, t_raycaster *rc)
{
	if (str[0] == 'R' && rc->globals.win_y > 0)
		freefile();
	else if (str[0] == 'N' && rc->globals.north_text)
		freefile();
	else if (str[0] == 'W' && rc->globals.west_text)
		freefile();
	else if (str[0] == 'E' && rc->globals.east_text)
		freefile();
	else if (str[0] == 'F' && (rc->globals.floor_color.r != -1 ||
				ft_char_num(str, ',') != 2))
		freefile();
	else if (str[0] == 'C' && (rc->globals.ceiling_color.r != -1 ||
				ft_char_num(str, ',') != 2))
		freefile();
	else if (str[0] == 'S' && str[1] == 'O' && rc->globals.south_text)
		freefile();
	else if (str[0] == 'S' && rc->globals.sprite_text)
		freefile();
	return (0);
}

void			assign_paths(char *file, t_raycaster *rc)
{
	int i;

	i = 1;
	if (file[0] == 'R' && check_double(file, rc) == 0)
		i = get_resolution(file, rc);
	else if (file[0] == 'N' && check_double(file, rc) == 0)
		i = get_path_north(file, rc);
	else if (file[0] == 'W' && check_double(file, rc) == 0)
		i = get_path_west(file, rc);
	else if (file[0] == 'E' && check_double(file, rc) == 0)
		i = get_path_east(file, rc);
	else if (file[0] == 'F' && check_double(file, rc) == 0)
		i = get_floor_color(file, rc);
	else if (file[0] == 'C' && check_double(file, rc) == 0)
		i = get_ceiling_color(file, rc);
	else if (file[0] == 'S' && file[1] == 'O' && check_double(file, rc) == 0)
		i = get_path_south(file, rc);
	else if (file[0] == 'S' && file[1] == ' ' && check_double(file, rc) == 0)
		i = get_path_sprite(file, rc);
	if (i < 0)
		freefile();
}
