/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 07:45:41 by jperez-r          #+#    #+#             */
/*   Updated: 2022/10/13 14:58:39 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**r;
	t_list	*current;
	t_list	*new;

	if (!lst)
		return (NULL);
	r = (t_list **)malloc(ft_lstsize(lst) * sizeof(*r));
	if (!r)
		return (NULL);
	*r = NULL;
	current = lst;
	while (current)
	{
		new = ft_lstnew(f(current->content));
		if (!new)
		{
			ft_lstclear(r, del);
			free(r);
			return (NULL);
		}
		ft_lstadd_back(r, new);
		current = current->next;
	}
	return (*r);
}
