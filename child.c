/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:09:31 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/05 15:59:10 by jperez-r         ###   ########.fr       */
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
		return (error_pipex(3, NULL));
	fdi = open(s[1], O_RDONLY);
	dup2(fdi, 0);
	cmd = ft_split(s[2], ' ');
	// Hay que liberar el split
	path = com_path(cmd[0]);
	if (!path)
	{
		close(fdi);
		return (-1);
	}
	dup2(fdp[1], STDOUT_FILENO);
	close(fdp[1]);
	execve(path, cmd, NULL);
	close(fdi);
	free (path);
	return (1);
}
