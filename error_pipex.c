/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:39:33 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/05 14:24:41 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_pipex(int er, char *cmd)
{
	if (er == 0)
		ft_putstr_fd(ft_strjoin("Error: Need 4 arguments:\n", cmd),2);
	if (er == 1)
		ft_putstr_fd("Error: Pipe not open\n", 2);
	if (er == 2)
		ft_putstr_fd("Error: PID incorrect\n", 2);
	if (er == 3)
		//ft_putstr_fd("Error. File not found\n", 2);
		perror("Error");
	if (er == 4)
		ft_putstr_fd(ft_strjoin("Error. Command not found: ", cmd),  2);
	if (er >= 5) /*Default error*/
		perror("Error");
	/*if (cmd)
		free (cmd);*/
	return(0);
}
