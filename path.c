/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:45:55 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/07 16:35:14 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*com_path(char *cmd)
{
	char	*path;

	path = ft_strjoin("/bin/", cmd);
	if (access (path, F_OK) == 0)
		return (path);
	path = ft_strjoin("/usr", path);
	if (access (path, F_OK) == 0)
		return (path);
	cmd = ft_strjoin(cmd, " \n");
	error_pipex(5, cmd);
	free (path);
	return (NULL);
}
