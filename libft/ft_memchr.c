/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:20:16 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/06 14:41:37 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	ch;
	char	*ps;
	size_t	i;

	i = 0;
	ps = (char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ps[i] == ch)
			return (ps + i);
		i++;
	}
	return (NULL);
}
