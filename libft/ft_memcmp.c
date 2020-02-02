/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:20:19 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/01 10:41:46 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n)
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
		n--;
	}
	return (0);
}
