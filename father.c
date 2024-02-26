/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:14:34 by jperez-r          #+#    #+#             */
/*   Updated: 2024/02/26 15:32:08 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	father(char **s, int *fdp)
{
	char	**cmd;
	char	*path;
	int		fdo;

	close(fdp[1]);
	fdo = open(s[4], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	cmd = ft_split(s[3], ' ');
	path = com_path(cmd[0]);
	dup2(fdp[0], STDIN_FILENO);
	close(fdp[0]);
	dup2(fdo, STDOUT_FILENO);
	execve(path, cmd, NULL);
	close(fdo);
	return (1);
}

/*int	father (char **s, int *fdp)
{
	//char	buff[250];
	int	fdo;
	char	**cmd;
	char	*path;
	//int state;

	close(fdp[1]);
	cmd = ft_split(s[3], ' ');
	path = ft_strjoin("usr/bin/", cmd[0]);

	//printf("el comando es: %s, la flag es %s y la ruta es %s\n", cmd[0],
									cmd[1], path);
	fdo = open(s[4], O_WRONLY);
	dup2(fdp[0], STDIN_FILENO);
	//read(fdp[0], buff, sizeof(buff));
	//printf("soy padre\nmi hijo me dice: %s\n", buff);
	dup2(fdo, STDOUT_FILENO);
	//wait(&state);
	//printf("soy padre\npid padre: %d\tpid hijo: %d\t\tstate: %d\n", getpid(),
									pid, state);
	close(fdp[0]);
	execve(path, cmd, NULL);
	close(fdo);
	return(1);
}*/
