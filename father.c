/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:14:34 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/07 17:05:14 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	father(char **s, int *fdp)
{
	char	**cmd;
	char	*path;
	int		fdo;

	close(fdp[1]);
	if (!can_write(s[4]))
		return (0);
	fdo = open(s[4], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	cmd = ft_split(s[3], ' ');
	path = com_path(cmd[0]);
	if (!path)
	{
		close(fdo);
		ft_free_double(cmd);
		return (-1);
	}
	dup2(fdp[0], STDIN_FILENO);
	close(fdp[0]);
	dup2(fdo, STDOUT_FILENO);
	execve(path, cmd, NULL);
	close(fdo);
	free (path);
	ft_free_double(cmd);
	return (1);
}
