SRCS	=			main.c	file_management.c	ft_str.c	read_map.c	solve.c	ft_print.c

OBJS	=			$(SRCS:.c=.o)

CC		=			gcc

RM		=			rm -f

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			bsq


all: ${NAME}

${NAME}: $(OBJS)
	${CC} ${CFLAGS} $^ -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
