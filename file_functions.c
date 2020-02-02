/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 11:47:30 by tuperera       #+#    #+#                */
/*   Updated: 2020/01/23 13:45:38 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				freefile(int count)
{
	while (count >= 0)
	{
		if (g_file[count])
			free(g_file[count]);
		count--;
	}
	if (g_file)
		free(g_file);
	ft_putstr_fd("Error occured.", 1);
	return (-1);
}

void			gnl(char *line, int fd, int i)
{
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		g_file[i] = (char *)calloc((ft_strlen(line) + 1), sizeof(char));
		if (!g_file[i])
			freefile(i);
		ft_strlcpy(g_file[i], line, (ft_strlen(line) + 1));
		free(line);
		i++;
	}
	g_file[i] = (char *)calloc((ft_strlen(line) + 1), sizeof(char));
	if (!g_file[i])
		freefile(i);
}

int				get_file(char *argv)
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
	g_file = (char **)malloc(sizeof(char *) * i);
	if (!g_file)
		return (-1);
	gnl(line, fd, i);
	ft_strlcpy(g_file[i], line, (ft_strlen(line) + 1));
	free(line);
	g_filelen = i;
	close(fd);
	return (0);
}
