/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:58:17 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/13 10:56:49 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux1;
	unsigned char	*aux2;

	i = 0;
	if (n == 0)
		return (0);
	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	while (aux1 && aux2[i] && aux1[i] == aux2[i] && i < n - 1)
		i++;
	return (aux1[i] - aux2[i]);
}
