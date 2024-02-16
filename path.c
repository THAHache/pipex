/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:45:55 by jperez-r          #+#    #+#             */
/*   Updated: 2024/02/16 22:02:47 by jperez-r         ###   ########.fr       */
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
			ft_putstr_fd("Error. Command not found\n", 2);
			return (NULL);
		}
	}
	return (path);
}
