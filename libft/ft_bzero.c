/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:20:56 by tuperera       #+#    #+#                */
/*   Updated: 2019/10/31 10:53:41 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	c = (char *)s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}
