/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 06:13:40 by jperez-r          #+#    #+#             */
/*   Updated: 2023/10/25 18:07:32 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Function for add a new node in the list
 * Función para agregar un luevo nodo a la lista
*/

t_list	*ft_lstnew(void const *content)
{
	t_list	*lis;

	lis = malloc(sizeof(*lis));
	if (!lis)
		return (0);
	lis->content = (void *)content;
	lis->next = NULL;
	return (lis);
}
