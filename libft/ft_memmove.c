/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:36:09 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/13 07:41:29 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*auxsrc;
	unsigned char	*auxdst;
	size_t			i;

	i = 0;
	if (!(src || dst) || len <= 0)
		return (dst);
	auxsrc = (unsigned char *)src;
	auxdst = (unsigned char *)dst;
	if (auxsrc > auxdst)
	{
		while (i < len)
		{
			auxdst[i] = auxsrc[i];
			i++;
		}
	}
	else
	{
		while (i < len--)
			auxdst[len] = auxsrc[len];
	}
	return (dst);
}
