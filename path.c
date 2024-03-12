/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:45:55 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/12 12:41:27 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*com_path(char *cmd)
{
	char	*path;
	char	*err;

	path = ft_strjoin("/bin/", cmd);
	if (access (path, F_OK) == 0)
		return (path);
	free (path);
	path = ft_strjoin("/usr/bin/", cmd);
	if (access (path, F_OK) == 0)
		return (path);
	err = ft_strjoin(cmd, "\n");
	error_pipex(5, err);
	free (path);
	free (err);
	return (NULL);
}
