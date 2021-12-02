SRC_DIR =			src/

INC_DIR =			inc/

QUEUE_DIR =			queue/

MVMNTS_DIR =		mvmnts/

QUEUE	=			\
					$(addprefix $(QUEUE_DIR), \
					ft_queueadd.c \
					ft_queuedel.c \
					ft_queuepop.c \
					) \
					test/test_queue.c

MVMNTS	=			\
					$(addprefix $(MVMNTS_DIR), \
					ft_push.c \
					ft_reverse_rotate.c \
					ft_rotate.c \
					ft_swap.c \
					)

SRCS	= 			$(addprefix $(SRC_DIR), \
					$(QUEUE) \
					$(MVMNTS) \
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			gcc

RM		=			-rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra -MD 

LDFLAGS	=			$(LIBFTNAME)

NAME	=			push_swap	

INC_ALL	=			\
					$(INC_DIR) \
					$(LIBFT)$(INC_DIR)

LIBFT	=			libft/

LIBFTNAME =			$(LIBFT)libft.a
