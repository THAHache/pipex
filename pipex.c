/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:56 by jperez-r          #+#    #+#             */
/*   Updated: 2024/02/16 22:39:12 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char **s)
{
	int		fdp[2];
	pid_t	pid;

	if (pipe (fdp) != 0) //mandar primero que hay un error y luego ya el return
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		if (!child(s, fdp))
		{
			close(fdp[0]);
			close(fdp[1]);
			return (-1);
		}
	}
	else
		father(s, fdp);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	/*if (argc == 4)
		función para ver si los argumentos son válidos*/
	if (argc != 5)
	{
		ft_putstr_fd("Error. Need 5 arguments\n", 2);
		return (0);
	}
	if (pipex(argv) == -1)
	{
		ft_putstr_fd("Error. Pipe or PID\n", 2);
		return (0);
	}
	if (!argv)
		return (0);
	system("leaks -q -- ./pipex");
	return (1);
}
