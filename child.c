/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:09:31 by jperez-r          #+#    #+#             */
/*   Updated: 2024/02/26 16:19:15 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(char **s, int *fdp)
{
	char	**cmd;
	char	*path;
	int		fdi;

	close(fdp[0]);
	if (access (s[1], F_OK) != 0)
		return (error_pipex(3));
	fdi = open(s[1], O_RDONLY);
	dup2(fdi, 0);
	cmd = ft_split(s[2], ' ');
	path = com_path(cmd[0]);
	dup2(fdp[1], STDOUT_FILENO);
	close(fdp[1]);
	execve(path, cmd, NULL);
	close(fdi);
	return (1);
}

/*int	child (char **s, int *fdp)
{
	char	**cmd;
	char	*path;

	close(fdp[0]);

	cmd = ft_split(s[2], ' ');
	path = ft_strjoin("/bin/", cmd[0]);
	dup2(fdp[1], STDOUT_FILENO);
	//printf("el comando es: %s, la flag es %s y la ruta es %s\n", cmd[0],
										cmd[1], path);
	//write(fdp[1], "hola, padre", strlen("hola, padre") + 1);
	//printf("soy hijo, mi pid es: %d\n", getpid());
	close(fdp[1]);
	execve(path, cmd, NULL);
	return (1);
}*/
