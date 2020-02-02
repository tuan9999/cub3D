/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:03:54 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/01 10:34:29 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (length && (*ptr1 || *ptr2))
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		else
		{
			ptr1++;
			ptr2++;
			length--;
		}
	}
	return (0);
}
