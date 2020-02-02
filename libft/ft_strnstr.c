/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:03:10 by tuperera       #+#    #+#                */
/*   Updated: 2019/10/31 10:57:36 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	int	check(char *haystack, const char *needle, size_t len)
{
	while (*haystack && *needle)
	{
		if (*haystack != *needle)
			return (0);
		haystack++;
		needle++;
		if (len == 0)
			return (0);
		len--;
	}
	return (*needle == '\0');
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*res;

	res = (char *)haystack;
	if (*needle == '\0')
		return (res);
	while (*res && len)
	{
		if (*res == *needle && check(res, needle, len))
			return (res);
		res++;
		len--;
	}
	return (NULL);
}
