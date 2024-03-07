#include "pipex.h"

extern char	**environ;

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

/*char	*com_path(char *cmd)
{
	char	*path;

	path = ft_strjoin("/bin/", cmd);
	if (access (path, F_OK) != 0)
	{
		path = ft_strjoin("/usr", path);
		if (access (path, F_OK) != 0)
		{
			cmd = ft_strjoin(cmd, " \n");
			error_pipex(5, cmd);
			free (path);
			return (NULL);
		}
	}
	return (path);
}*/
/*int	child (char **s, int *fdp)
{
	char	**cmd;
	char	*path;

	close(fdp[0]);

	cmd = ft_split(s[2], ' ');
	path = ft_strjoin("/bin/", cmd[0]);
	dup2(fdp[1], STDOUT_FILENO);
	//printf("el comando es: %s, la flag es %s y la ruta es %s\n", cmd[0],
										cmd[1], path);
	//write(fdp[1], "hola, padre", strlen("hola, padre") + 1);
	//printf("soy hijo, mi pid es: %d\n", getpid());
	close(fdp[1]);
	execve(path, cmd, NULL);
	return (1);
}*/


/*int	father (char **s, int *fdp)
{
	//char	buff[250];
	int	fdo;
	char	**cmd;
	char	*path;
	//int state;

	close(fdp[1]);
	cmd = ft_split(s[3], ' ');
	path = ft_strjoin("usr/bin/", cmd[0]);

	//printf("el comando es: %s, la flag es %s y la ruta es %s\n", cmd[0],
									cmd[1], path);
	fdo = open(s[4], O_WRONLY);
	dup2(fdp[0], STDIN_FILENO);
	//read(fdp[0], buff, sizeof(buff));
	//printf("soy padre\nmi hijo me dice: %s\n", buff);
	dup2(fdo, STDOUT_FILENO);
	//wait(&state);
	//printf("soy padre\npid padre: %d\tpid hijo: %d\t\tstate: %d\n", getpid(),
									pid, state);
	close(fdp[0]);
	execve(path, cmd, NULL);
	close(fdo);
	return(1);
}*/


int	pipex2(char **s)
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

/*int   pipex1(char **av)
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

int	mainprueba(int argc, char *argv[])
{
	//int pi;
	if (argc == 1)
		return (0);
	//if (argc == 4)
		//función para ver si los argumentos son válidos
	if (argc != 5)
	{
		ft_putstr_fd("Error. Need 5 arguments\n", 2);
		return (0);
	}
	if (pipex2(argv) == -1)
	{
		ft_putstr_fd("Error. Pipe or PID\n", 2);
		return (0);
	}
	//pipex2(argv);
	//pipex3();
	if (!argv)
		return 0;
	/*if (!error_controlpx(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}*/
	//pipex(argv);
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
