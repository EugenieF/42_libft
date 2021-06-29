# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efrancon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 09:25:34 by efrancon          #+#    #+#              #
#    Updated: 2021/05/21 10:35:08 by efrancon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
			ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_isspace.c ft_sort_int_tab.c ft_atoi_with_pointer.c clean_free.c \
			ft_lstnew.c  ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
			ft_lstadd_front.c ft_lstadd_back.c ft_lstiter.c ft_lstmap.c \
			get_next_line.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCLUDE		= libft.h

RM			= rm -f


.c.o:
				@${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				@echo "Libft -> linking : $@"
				@ar rc ${NAME} ${OBJS}
				@ranlib ${NAME}

all:		${NAME}

clean:
				@echo "Libft -> removing objects"
				@${RM} ${OBJS}

fclean:		clean
				@echo "Libft -> removing ${NAME}"
				@${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
