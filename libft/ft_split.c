/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:16:32 by amepocch          #+#    #+#             */
/*   Updated: 2022/10/13 16:11:33 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_words(char const *s, char c)
{
	int	i;
	int	cont;

	i = 1;
	if (ft_strlen(s) == 0)
		return (0);
	cont = 1;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			cont++;
		i++;
	}
	return (cont);
}

static size_t	ft_wordlen(char const *s, int a, int z, char c)
{
	size_t	wlen;

	wlen = 0;
	while (a <= z)
	{
		if (s[a] != c)
		{
			wlen++;
		}
		a++;
	}
	return (wlen);
}

static char	*ft_set_word(char const *s, int a, int z, char c)
{
	int		k;
	char	*w;

	k = 0;
	w = (char *)malloc(ft_wordlen(s, a, z, c) + 1);
	if (!w)
		return (NULL);
	while (a <= z)
	{
		if (s[a] != c)
		{
			w[k] = s[a];
			k++;
		}
		a++;
	}
	w[k] = '\0';
	return (w);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		aux;
	char	**word;

	i = 0;
	j = 0;
	aux = 0;
	if (!s)
		return (NULL);
	word = (char **)malloc(sizeof(char *) * (ft_num_words(s, c) + 1));
	if (!word)
		return (NULL);
	while (s[++i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
		{
			word[j++] = ft_set_word(s, aux, i, c);
			aux = i + 1;
		}
	}
	if (s[i - 1] != c && ft_strlen(s) > 0)
		word[j++] = ft_set_word(s, aux, i - 1, c);
	word[j] = NULL;
	return (word);
}
