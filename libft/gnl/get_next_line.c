/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:25:30 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/16 17:40:00 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	put_line(char **line, char **aux, int reader)
{
	char	*tmp;
	int		pos;

	if (reader == -1)
		return (-1);
	pos = gnl_strchr(*aux, '\n');
	if (pos >= 0)
	{
		*line = ft_substr(*aux, 0, pos);
		tmp = ft_substr(*aux, pos + 1, ft_strlen(*aux));
		free(*aux);
		*aux = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(*aux);
		free(*aux);
		*aux = NULL;
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*aux[4096];
	char		*buff;
	int			reader;
	int			ctrl;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buff = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	if (!aux[fd])
		aux[fd] = ft_strdup("");
	reader = 1;
	while (gnl_strchr(aux[fd], '\n') == -1 && reader > 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader > 0)
		{
			buff[reader] = '\0';
			aux[fd] = gnl_strjoin(aux[fd], buff);
		}
	}
	ctrl = put_line(line, &aux[fd], reader);
	free(buff);
	return (ctrl);
}
