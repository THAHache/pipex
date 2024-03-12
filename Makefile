# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 19:24:26 by jperez-r          #+#    #+#              #
#    Updated: 2024/03/12 16:38:12 by jperez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	pipex.c \
			error_pipex.c \
			path.c \
			is_access.c \
			child.c \
			father.c

LIBFT	=	libft/

GNL		=	gnl/

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
RESET	=	\033[0m

NAME	=	pipex

.o:	.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}	:	${OBJS}
			@make -C ${LIBFT}
			@if [ -f ${LIBFT}/libft.a ]; then \
				echo "${GREEN}********* CREATION SUCCESS *********${RESET}"; \
			else \
				echo "${RED}********* FAIL CREATION *********${RESET}"; \
			fi
			@${CC} ${OBJS} -L${LIBFT} -lft -o ${NAME}


all		:	${NAME}

clean	:
			@make -C ${LIBFT} clean
			rm -f ${OBJS}
			@echo "${YELLOW}********* CLEAN SUCCESS *********${RESET}"; \

fclean	:	clean
			@make -C ${LIBFT} fclean
			rm -f ${NAME}
			@echo "${YELLOW}********* FCLEAN SUCCESS *********${RESET}"; \

re		:	fclean all

.PHONY	:	all clean fclean re
