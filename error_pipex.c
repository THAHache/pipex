/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:39:33 by jperez-r          #+#    #+#             */
/*   Updated: 2024/02/29 15:26:21 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_pipex(int er)
{
	if (er == 0)
		ft_putstr_fd("Error: Need 4 arguments: file1 command1 command2 file2\n", 2);
	if (er == 1)
		ft_putstr_fd("Error: Pipe not open\n", 2);
	if (er == 2)
		ft_putstr_fd("Error: PID incorrect\n", 2);
	if (er == 3)
		//ft_putstr_fd("Error. File not found\n", 2);
		perror("Error");
	if (er >= 4) /*Default error*/
		perror("Error");
	return(0);
}
