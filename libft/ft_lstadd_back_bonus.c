/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:02:22 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/03 17:50:06 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (*alst == NULL)
	{
		(*alst) = new;
		return ;
	}
	temp = *alst;
	if (temp->next == NULL)
	{
		temp->next = new;
		return ;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
