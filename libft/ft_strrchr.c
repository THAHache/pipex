/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:04:49 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/13 10:21:14 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		auxc;
	char	*auxs;

	i = 0;
	auxc = -1;
	auxs = (char *)s;
	while (auxs[i] != '\0')
	{
		if (auxs[i] == c)
			auxc = i;
		i++;
	}
	if (auxs[i] == c)
		return (&auxs[i]);
	if (auxc < 0)
		return (NULL);
	return (&auxs[auxc]);
}
