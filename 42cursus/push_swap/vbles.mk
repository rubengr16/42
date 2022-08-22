SRC_DIR	=			src/

INC_DIR	=			inc/

QUEUE_DIR	=		queue/

MVMNTS_DIR	=		mvmnts/

PARSER_DIR	=		parser/

ALGORITHM_DIR	=	algorithm/

PUSH_SWAP	=		push_swap.c

QUEUE	=			\
					$(addprefix $(QUEUE_DIR), \
					queueinit.c \
					queueadd.c \
					queuedel.c \
					queuepop.c \
					)

MVMNTS	=			\
					$(addprefix $(MVMNTS_DIR), \
					push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c \
					)

PARSER	=			\
					$(addprefix $(PARSER_DIR), \
					argtostack.c \
					)

ALGORITHM	= 	    \
					$(addprefix $(ALGORITHM_DIR), \
					threeelems.c \
					mergesort.c \
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
