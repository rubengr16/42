SRC_DIR	=			src/

INC_DIR	=			inc/

QUEUE_DIR	=		queue/

MVMNTS_DIR	=		mvmnts/

PARSER_DIR	=		parser/

ALGORITHM_DIR	=	algorithm/

PUSH_SWAP	=		push_swap.c

QUEUE	=			\
					$(addprefix $(QUEUE_DIR), \
					ft_queueinit.c \
					ft_queueadd.c \
					ft_queuedel.c \
					ft_queuepop.c \
					)

MVMNTS	=			\
					$(addprefix $(MVMNTS_DIR), \
					ft_push.c \
					ft_reverse_rotate.c \
					ft_rotate.c \
					ft_swap.c \
					)

PARSER	=			\
					$(addprefix $(PARSER_DIR), \
					ft_argdigit.c \
					ft_argtostack.c \
					)

ALGORITHM	= 	    \
					$(addprefix $(ALGORITHM_DIR), \
					ft_threeelems.c \
					)

SRCS	= 			$(addprefix $(SRC_DIR), \
					$(QUEUE) \
					$(MVMNTS) \
					$(PARSER) \
					$(ALGORITHM) \
					$(PUSH_SWAP) \
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
