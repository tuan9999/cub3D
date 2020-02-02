/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:03:28 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/08 11:09:57 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		digitcount(long n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		count;
	char	*ret;
	long	nb;

	nb = n;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	count = digitcount(nb);
	ret = (char *)malloc(sizeof(char) * count + 1);
	if (!ret)
		return (NULL);
	ret[count] = '\0';
	count--;
	if (nb < 0)
	{
		ret[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		ret[count] = (nb % 10) + '0';
		nb /= 10;
		count--;
	}
	return (ret);
}
