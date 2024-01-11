/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 06:52:24 by jperez-r          #+#    #+#             */
/*   Updated: 2022/10/13 17:34:39 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dstlen(char *s1, char *set)
{
	size_t		i;
	size_t		len;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (s1[i] == '\0')
		return (0);
	len = 0;
	while (s1[i] != '\0')
	{
		i++;
		len++;
	}
	i--;
	while (ft_strchr(set, s1[i]) != NULL)
	{
		i--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		lendst;
	char		*dst;
	char		*auxs1;
	char		*auxset;

	if (!s1 || !set)
		return (NULL);
	auxs1 = (char *)s1;
	auxset = (char *)set;
	lendst = ft_dstlen(auxs1, auxset);
	if (lendst == 0)
		return (ft_strdup(""));
	dst = malloc(sizeof(*dst) * (lendst + 1));
	if (!dst)
		return (NULL);
	while (*auxs1 && ft_strchr(auxset, *auxs1) != NULL)
		auxs1++;
	i = -1;
	while (++i < lendst)
		dst[i] = *auxs1++;
	dst[i] = '\0';
	return (dst);
}
