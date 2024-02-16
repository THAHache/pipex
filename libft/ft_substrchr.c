/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:23:24 by jperez-r          #+#    #+#             */
/*   Updated: 2024/02/16 21:17:46 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strchr_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substrchr(char *s, char c)
{
	char	*dst;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = strchr_len(s, c);
	if (!len)
		return (s);
	dst = malloc(len);
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
