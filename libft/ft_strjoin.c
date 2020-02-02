/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:49:28 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/07 15:41:26 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		ret[i] = *s2;
		i++;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}
