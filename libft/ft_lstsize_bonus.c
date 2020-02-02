/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:57:59 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/03 17:50:49 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	else
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			count++;
		}
	}
	count++;
	return (count);
}
