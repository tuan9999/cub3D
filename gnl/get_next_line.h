/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:03:14 by tuperera       #+#    #+#                */
/*   Updated: 2019/12/07 13:02:06 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				get_next_line(int fd, char **line);
int				ft_isin(char *s);
void			prep_buffer(char *buffer, char *orig);

#endif
