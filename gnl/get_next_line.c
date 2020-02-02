/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:03:17 by tuperera       #+#    #+#                */
/*   Updated: 2019/12/16 16:32:58 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char		*populateret(char *line, char *ret, char **buffer)
{
	size_t i;

	i = 0;
	if (line != NULL)
	{
		while (line[i] != '\0')
		{
			ret[i] = line[i];
			i++;
		}
		free(line);
	}
	while (**buffer != '\0' && **buffer != '\n')
	{
		ret[i] = **buffer;
		(*buffer)++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static char		*join_line(char *line, char *buffer)
{
	char	*ret;
	char	*orig;

	orig = buffer;
	ret = (char *)malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (ret == NULL)
	{
		free(line);
		return (NULL);
	}
	ret = populateret(line, ret, &buffer);
	prep_buffer(buffer, orig);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	ssize_t		size;
	static char buffer[BUFFER_SIZE + 1];
	int			ret;

	*line = NULL;
	ret = 0;
	while (ret == 0)
	{
		if (!*buffer)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			if (size <= 0)
			{
				buffer[0] = '\0';
				ret = size;
				*line = (ret == 0) ? join_line(*line, buffer) : NULL;
				break ;
			}
			buffer[size] = '\0';
		}
		ret = (ft_isin(buffer) == 1) ? 1 : ret;
		*line = join_line(*line, buffer);
		ret = (*line == NULL) ? -1 : ret;
	}
	return (ret);
}
