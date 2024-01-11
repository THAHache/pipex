/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 06:54:27 by jperez-r          #+#    #+#             */
/*   Updated: 2022/12/28 16:52:39 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux2;

	if (lst && del)
	{
		aux = *lst;
		while (aux)
		{
			aux2 = aux->next;
			del(aux->content);
			free(aux);
			aux = aux2;
		}
		*lst = NULL;
	}
}
