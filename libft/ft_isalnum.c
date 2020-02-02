/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:32:45 by tuperera       #+#    #+#                */
/*   Updated: 2019/10/31 18:15:54 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (!(c >= '0' && c <= '9'))
	{
		if (!(c >= 'a' && c <= 'z'))
			if (!(c >= 'A' && c <= 'Z'))
				return (0);
	}
	return (1);
}