# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 22:28:09 by jperez-r          #+#    #+#              #
#    Updated: 2024/03/07 14:31:36 by jperez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = ./

SRCS    = ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_free_double.c \
		ft_strdup.c \
		ft_substr.c \
		ft_substrchr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_intlen.c \
		ft_pow.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstsize.c \
		ft_lstmap.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJS    = ${SRCS:.c=.o}

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

NAME    = libft.a

.o:	.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}		:	${OBJS}
				@ar rc ${NAME} ${OBJS}
				@ranlib ${NAME}

all 		:   ${NAME}

clean 		:
				@rm -f ${OBJS} .o

fclean 		:	clean
				@rm -f ${NAME}

re 			:   fclean all

.PHONY		:	all clean fclean re
