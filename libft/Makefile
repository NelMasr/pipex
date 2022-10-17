# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-masr </var/mail/nel-masr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 11:06:14 by nel-masr          #+#    #+#              #
#    Updated: 2021/03/30 13:20:30 by nel-masr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_isdigit.c  ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c \
ft_strtrim.c ft_bzero.c ft_isprint.c ft_memmove.c ft_split.c ft_strlen.c \
ft_substr.c ft_calloc.c ft_itoa.c ft_memset.c ft_strchr.c ft_strmapi.c \
ft_tolower.c ft_isalnum.c ft_memccpy.c ft_putchar_fd.c ft_strdup.c \
ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memchr.c ft_putendl_fd.c \
ft_strjoin.c ft_strnstr.c ft_isascii.c  ft_memcmp.c   ft_putnbr_fd.c \
ft_strlcat.c    ft_strrchr.c  get_next_line.c get_next_line_utils.c \

BONUS = ft_lstiter.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstmap.c \
ft_lstclear.c ft_lstadd_back.c ft_lstdelone.c ft_lstlast.c \

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

all: $(NAME)

$(NAME):
		${CC} ${FLAGS} -c ${SRCS}
		ar rc $(NAME) ${OBJS}
		ranlib $(NAME)

bonus:
		${CC} ${FLAGS} -c ${SRCS} ${BONUS}
		ar rc $(NAME) ${OBJS} ${OBJSBONUS}
		ranlib $(NAME)

clean:
		rm -rf ${OBJS} ${OBJSBONUS}

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
