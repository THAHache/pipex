/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:06:42 by jperez-r          #+#    #+#             */
/*   Updated: 2023/01/26 20:41:11 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len_base(long n, int base)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long n, int base)
{
	size_t		len;
	char		*dst;
	long		mod;

	len = ft_len_base(n, base);
	dst = malloc(len + 1);
	if (!dst)
		return (0);
	dst[len] = '\0';
	len--;
	while (n)
	{
		mod = n % base;
		if (mod >= 10 && mod <= 15)
			dst[len] = mod + 87;
		else
			dst[len] = mod + 48;
		n /= base;
		len--;
	}
	return (dst);
}
