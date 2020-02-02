/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 11:51:22 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/04 15:36:22 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || *alst == NULL)
		(*alst) = new;
	else
	{
		new->next = (*alst);
		(*alst) = new;
	}
}
