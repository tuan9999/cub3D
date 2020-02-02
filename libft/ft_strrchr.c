/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:13:07 by tuperera       #+#    #+#                */
/*   Updated: 2019/10/31 18:59:21 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr)
		ptr++;
	while (*ptr != *s)
	{
		if (*ptr == c)
			return (ptr);
		else
			ptr--;
	}
	if (*ptr == c)
		return (ptr);
	return (NULL);
}
