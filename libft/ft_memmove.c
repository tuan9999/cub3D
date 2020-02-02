/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:20:23 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/05 20:16:51 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*psrc;
	char	*pdst;
	size_t	i;

	if (dst == src && src == NULL)
		return (dst);
	psrc = (char *)src;
	pdst = (char *)dst;
	i = 0;
	if (len > 0 && (&psrc[i] <= &pdst[i] && &psrc[len - 1] > &pdst[i]))
		while (len > 0)
		{
			pdst[len - 1] = psrc[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	return (dst);
}
