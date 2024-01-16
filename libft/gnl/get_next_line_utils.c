/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:23:28 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/16 17:38:16 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strchr(const char *s, int c)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)s;
	while (aux[i] != '\0')
	{
		if (aux[i] == c)
			return (i);
		i++;
	}
	if (aux[i] == c)
		return (i);
	return (-1);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		len_s1;
	int		len_s2;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!dst)
		return (NULL);
	while (++i < len_s1)
		dst[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		dst[len_s1 + i] = s2[i];
	dst[len_s1 + i] = '\0';
	free(s1);
	return (dst);
}
