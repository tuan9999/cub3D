/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 12:17:36 by tuperera       #+#    #+#                */
/*   Updated: 2019/11/08 17:11:42 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;
	t_list	*nne;
	t_list	*ret;

	new = !lst ? NULL : ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	ret = new;
	nne = ft_lstnew(f(lst->next->content));
	new->next = nne;
	first = lst->next->next;
	while (first)
	{
		new = ft_lstnew(f(first->content));
		if (!new)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		nne->next = new;
		nne = new;
		first = first->next;
	}
	return (ret);
}
