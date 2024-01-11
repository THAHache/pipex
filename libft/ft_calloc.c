/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:38:45 by jperez-r          #+#    #+#             */
/*   Updated: 2023/01/26 20:09:43 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Before new norminette, malloc was an unique line:
** if (!(dst = (void *)malloc(size * count)))
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = (void *)malloc(size * count);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, size * count);
	return (dst);
}
