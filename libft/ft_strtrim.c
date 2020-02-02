/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:54:23 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/08 11:14:36 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	checkcmp(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	int	getlength(char const *s1, char const *set)
{
	int len;
	int ch;

	ch = 0;
	len = 0;
	while (s1[len])
		len++;
	len--;
	while (checkcmp(s1[ch], set) == 1)
		ch++;
	while (checkcmp(s1[len], set) == 1)
		len--;
	if ((len - ch) <= 0)
		return (0);
	return (len - ch);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = getlength(s1, set) + 1;
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (!ret)
		return (NULL);
	while (checkcmp(*s1, set) == 1)
		s1++;
	j = 0;
	while (*s1 && j < i)
	{
		ret[j] = *s1;
		j++;
		s1++;
	}
	ret[j] = '\0';
	return (ret);
}
