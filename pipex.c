/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:32:56 by jperez-r          #+#    #+#             */
/*   Updated: 2024/02/13 17:22:54 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char **environ;

void	free_line(char *line)
{
	free(line);
	line = NULL;
}

int	error_controlpx(char **s)
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

int	pipex(char **s)
{
	int		fd;
	int		ret_value;
	char	*line;

	line = NULL;
	fd = open(s[1], O_RDONLY);
	ret_value = 1;
	while (ret_value == 1)
	{
		line = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		if (!line)
			return (-1);
		ret_value = get_next_line(fd, &line);
		printf("%s\n", line);
		free_line(line);
	}
	close(fd);
	return (1);
}

/*int   pipex(char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open(av[1], O_RDONLY);
  fd2 = open(av[2], O_RDONLY);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  get_next_line(fd1, &line);
  printf("%s\n", line);
  get_next_line(fd2, &line);
  printf("%s\n", line);
  return (0);
}*/

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc != 5)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	/*if (!error_controlpx(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}*/
	//pipex(argv);
	if(!argv)
		return 0;
	/*char *arg[] = {"/.ls", "-la", NULL};
	char *envp[] = {"-la", NULL};
	execve("/bin/ls", arg, envp);*/
	/*char **env = environ;
	while (*env)
	{
		if(!ft_strncmp(ft_substr(*env, 0, 4), "PATH", 4))
			printf("%s\n", *env);
		env++;
	}*/

	/*int s;

	s = socket(PF_INET, SOCK_STREAM, 0);

	if (s == -1) { // some error has occurred
		// prints "socket error: " + the error message:
		perror("socket error");
	}

	// similarly:
	if (listen(s, 10) == -1) {
		// this prints "an error: " + the error message from errno:
		printf("an error: %s\n", strerror(errno));
	}*/
	//system("leaks -q -- ./pipex");
	return (1);
}
