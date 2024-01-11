/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:56 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/11 20:06:40 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_line(char *line)
{
	free(line);
	line = NULL;
}

int		error_controlpx(char **s)
{
	int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	fd = open(s[1], O_RDONLY);
	ret_value = 1;
	while (ret_value == 1)
	{
		ret_value = get_next_line(fd, &line);
		printf("%s\n", line);
		free_line(line);
	}
	close(fd);
	return (1);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc != 5)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!error_controlpx(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	//pipex(argv);

	return (1);
}
