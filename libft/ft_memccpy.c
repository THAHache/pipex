/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:27:33 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/13 06:43:53 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*auxsrc;
	unsigned char	*auxdst;

	i = 0;
	if (!(src || dst))
		return (NULL);
	auxsrc = (unsigned char *)src;
	auxdst = (unsigned char *)dst;
	dst++;
	while (i < n)
	{
		auxdst[i] = auxsrc[i];
		if (auxsrc[i] == (unsigned char)c)
		{
			return (dst);
		}
		i++;
		dst++;
	}
	return (NULL);
}
