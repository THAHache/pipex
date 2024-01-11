/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 01:26:12 by jperez-r          #+#    #+#             */
/*   Updated: 2022/10/13 17:16:39 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!dst)
		return (NULL);
	while (i++ < len_s1)
		dst[i - 1] = s1[i - 1];
	i = 0;
	while (i < len_s2)
	{
		dst[len_s1 + i] = s2[i];
		i++;
	}
	dst[len_s1 + i] = '\0';
	return (dst);
}
