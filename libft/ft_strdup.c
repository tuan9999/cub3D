/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:47:55 by tuperera       #+#    #+#                */
/*   Updated: 2019/10/31 18:22:54 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ps1;

	i = 0;
	while (s1[i])
		i++;
	i++;
	ps1 = (char *)malloc(sizeof(char) * i);
	if (!ps1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ps1[i] = s1[i];
		i++;
	}
	ps1[i] = '\0';
	return (ps1);
}
