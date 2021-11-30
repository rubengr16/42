SRC_DIR =			src/

INC_DIR =			inc/

QUEUE_DIR =			queue/

MVMNTS_DIR =		mvmnts/

QUEUE =				\
					$(addprefix $(QUEUE_DIR), \
					ft_queueadd.c \
					ft_queuedel.c \
					ft_queuepop.c \
					)

MVMNTS =			\
					$(addprefix $(MVMNTS_DIR), \
					ft_push.c \
					ft_reverse_rotate.c \
					ft_rotate.c \
					ft_swap.c \
					)

SRCS = 		

OBJS	=			$(SRCS:.c=.o)

CC		=			gcc

RM		=			-rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			push_swap	

LIBFT	=			$(SRC_DIR)libft/

LIBFTNAME =			libft.a
