/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:45:55 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/04 14:43:21 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*com_path(char *cmd)
{
	char	*path;

	path = ft_strjoin("/bin/", cmd);
	if (access (path, F_OK) != 0)
	{
		path = ft_strjoin("/usr", path);
		if (access (path, F_OK) != 0)
		{
			error_pipex(4, ft_strjoin(cmd, " \n"));
			return (NULL);
		}
	}
	return (path);
}
