/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:56 by jperez-r          #+#    #+#             */
/*   Updated: 2024/02/26 16:05:47 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char **s)
{
	int		fdp[2];
	pid_t	pid;

	if (pipe (fdp) != 0)
		return (error_pipex(1));
	pid = fork();
	if (pid < 0)
		return (error_pipex(2));
	if (pid == 0)
	{
		if (!child(s, fdp))
		{
			close(fdp[1]);
			return (0);
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
		//sleep(30);
	if (argc != 5)
		return (error_pipex(0));
	if (!pipex(argv))
	{
		//system("leaks -q -- ./pipex");
		return (0);
	}
	//system("leaks -q -- ./pipex");
	return (1);
}
