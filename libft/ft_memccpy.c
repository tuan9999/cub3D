/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:19:51 by tuperera       #+#    #+#                */
/*   Updated: 2019/10/30 14:09:42 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	ch;
	char	*pdst;
	char	*psrc;
	size_t	i;

	pdst = (char *)dst;
	psrc = (char *)src;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		*pdst = *psrc;
		pdst++;
		if (*psrc == ch)
			return (pdst);
		psrc++;
		i++;
	}
	return (NULL);
}
