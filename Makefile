NAME	=	pipex

SRCS	=	srcs/pipex.c			\
			srcs/tweaked_split.c	\

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
DEBUG 	=	-g3

LIBFT_DIR =	libft/libft.a

.c.o:
			${CC} ${CFLAGS} ${DEBUG} -c $< -o ${<:.c=.o}

all:
			$(MAKE) -j $(NAME)

$(NAME):	$(OBJS)
			${CC} $(CFLAGS) $(DEBUG) -o $(NAME) $(OBJS) $(LIBFT_DIR)

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
