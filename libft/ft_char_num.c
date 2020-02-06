/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_num.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:07:15 by tuperera       #+#    #+#                */
/*   Updated: 2020/02/06 16:18:16 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_char_num(const char *str, int c)
{
	char	*p;
	int		count;

	p = (char *)str;
	count = 0;
	while (*p)
	{
		if (*p == (unsigned char)c)
			count++;
		p++;
	}
	return (count);
}
