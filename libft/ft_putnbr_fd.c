/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:11:27 by jperez-r          #+#    #+#             */
/*   Updated: 2020/12/10 23:10:25 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long int n, int fd)
{
	long int	nb;
	int			i;
	long int	num_act;

	nb = n;
	i = ft_intlen(nb);
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
		i--;
	}
	while (i > 0)
	{
		num_act = nb / ft_pow(10, i);
		ft_putchar_fd(num_act + 48, fd);
		nb %= ft_pow(10, i);
		i--;
	}
}
