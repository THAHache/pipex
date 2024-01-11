/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:38:08 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/13 09:35:56 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)s;
	while (aux[i] != '\0')
	{
		if (aux[i] == c)
			return (&aux[i]);
		i++;
	}
	if (aux[i] == c)
		return (&aux[i]);
	return (NULL);
}
