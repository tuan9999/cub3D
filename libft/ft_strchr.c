/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:53:48 by tuperera       #+#    #+#                */
/*   Updated: 2019/10/29 18:05:42 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char *p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (unsigned char)c)
			return (p);
		else
			p++;
	}
	if (*p == (unsigned char)c)
		return (p);
	else
		return (NULL);
}
