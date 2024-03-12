/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:39:33 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/12 17:04:56 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_pipex(int er, char *cmd)
{
	char	*msg;

	msg = NULL;
	if (er == 0)
		msg = ft_strjoin("Error: Need 4 arguments:\n", cmd);
	else if (er == 1)
		ft_putstr_fd("Error: Pipe not open\n", 2);
	else if (er == 2)
		ft_putstr_fd("Error: PID incorrect\n", 2);
	else if (er == 3)
		msg = ft_strjoin("Error: No such file or directory: ", cmd);
	else if (er == 4)
		msg = ft_strjoin("Error: Permission denied: ", cmd);
	else if (er == 5)
		msg = ft_strjoin("Error. Command not found: ", cmd);
	else if (er > 5)
		perror("Error");
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		free (msg);
	}
	return (0);
}
