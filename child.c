/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:09:31 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/12 12:36:01 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(char **s, int *fdp)
{
	char	**cmd;
	char	*path;
	int		fdi;

	close(fdp[0]);
	if (!can_read(s[1]))
		return (0);
	fdi = open(s[1], O_RDONLY);
	dup2(fdi, STDIN_FILENO);
	cmd = ft_split(s[2], ' ');
	path = com_path(cmd[0]);
	if (!path)
	{
		close(fdi);
		ft_free_double(cmd);
		return (-1);
	}
	dup2(fdp[1], STDOUT_FILENO);
	close(fdp[1]);
	execve(path, cmd, NULL);
	close(fdi);
	free (path);
	ft_free_double(cmd);
	return (1);
}
