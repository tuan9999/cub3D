/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:06:01 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/08 15:20:10 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if (len <= 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
