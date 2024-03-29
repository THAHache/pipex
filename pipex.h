/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:30:59 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/12 18:18:30 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./libft/gnl/get_next_line.h"

int		error_pipex(int er, char *cmd);

int		can_read(char *s);
int		can_write(char *s);
char	*com_path(char *cmd);
int		child(char **s, int *fdp);
int		wait_child(void);
int		father(char **s, int *fdp);

int		pipex(char **s);
int		main(int argc, char *argv[]);

#endif
