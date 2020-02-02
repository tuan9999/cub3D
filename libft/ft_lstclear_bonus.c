/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:06:41 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/03 17:50:19 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	current = NULL;
	if (!lst)
		return ;
	while (*lst)
	{
		current = (*lst);
		(*lst) = (*lst)->next;
		if (current)
		{
			del(current->content);
			free(current);
		}
	}
}
