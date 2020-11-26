# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mryan <mryan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 12:47:36 by mryan             #+#    #+#              #
#    Updated: 2020/11/14 16:43:29 by mryan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_strmapi.c \
	ft_itoa.c \
	ft_split.c

BONUS	= ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

BONOBJS	= ${BONUS:.c=.o}

OBJS	= ${SRC:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS} ${libft.h}
			ranlib ${NAME}

bonus:		${OBJS} ${BONOBJS}
			ar rc ${NAME} ${OBJS} ${BONOBJS} ${libft.h}
			ranlib ${NAME}

clean:
			${RM} ${OBJS} ${BONOBJS}

fclean:		clean
			${RM} ${NAME} ${BONOBJS}

re:			fclean all

norme:
			norminette ${SRC}