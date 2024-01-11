/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:07:44 by jperez-r          #+#    #+#             */
/*   Updated: 2023/12/26 19:00:49 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Check if the character is a number
 * Comprobar si el caracter es un número
*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_isnum(int c)
{
	if (c == 43 || c == 45 || (c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}
