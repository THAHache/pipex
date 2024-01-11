/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:37:13 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/13 06:44:03 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*auxsrc;
	char	*auxdst;

	i = 0;
	if (!(src || dst))
		return (NULL);
	auxsrc = (char *)src;
	auxdst = (char *)dst;
	while (i < n)
	{
		auxdst[i] = auxsrc[i];
		i++;
	}
	return (dst);
}
