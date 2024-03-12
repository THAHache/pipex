/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:56 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/12 12:43:11 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char **s)
{
	int		fdp[2];
	pid_t	pid;

	if (pipe (fdp) != 0)
		return (error_pipex(1, NULL));
	pid = fork();
	if (pid < 0)
		return (error_pipex(2, NULL));
	if (pid == 0)
	{
		if (!child(s, fdp))
		{
			close(fdp[1]);
			return (0);
		}
	}
	else if (!father(s, fdp))
	{
		close(fdp[0]);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc != 5)
		return (error_pipex(0, "file1 command1 command2 file2\n"));
	if (!pipex(argv))
	{
		return (0);
	}
	return (1);
}
