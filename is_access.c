/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:11:29 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/07 16:55:38 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	can_read(char *s)
{
	char	*err;
	int		ret;

	err = NULL;
	ret = 1;
	if (access (s, F_OK) != 0)
		ret = error_pipex(3, NULL);
	else if (access (s, R_OK) != 0)
	{
		err = ft_strjoin(s, "\n");
		ret = error_pipex(4, err);
	}
	if (err)
		free(err);
	return (ret);
}

int	can_write(char *s)
{
	char	*err;
	int		ret;

	err = NULL;
	ret = 1;
	if (access (s, F_OK) != 0)
		return (ret);
	if (access (s, W_OK) == 0)
		return (ret);
	err = ft_strjoin(s, "\n");
	ret = error_pipex(4, err);
	free(err);
	return (ret);
}
