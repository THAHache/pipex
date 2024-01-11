/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:25:30 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/11 20:08:36 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	put_line(char **line, char **aux)
{
	char	*tmp;
	int		pos;

	pos = gnl_strchr(*aux, '\n');
	if (pos >= 0)
	{
		*line = ft_substr(*aux, 0, pos);
		tmp = ft_substr(*aux, pos + 1, (const) ft_strlen(*aux));
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
	//while (gnl_strchr(aux[fd], '\n') == -1
	//		&& (reader = read(fd, buff, BUFFER_SIZE)) > 0)
	while (gnl_strchr(aux[fd], '\n') == -1 && read(fd, buff, BUFFER_SIZE) > 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		buff[reader] = '\0';
		aux[fd] = gnl_strjoin(aux[fd], buff);
	}
	if (reader == -1)
		ctrl = -1;
	else
		ctrl = put_line(line, &aux[fd]);
	free(buff);
	return (ctrl);
}
