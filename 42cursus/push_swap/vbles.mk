SRC_DIR	=			src/

INC_DIR	=			inc/

QUEUE_DIR	=		queue/

BTREE_DIR	=		btree/

STACK_DIR	=		stack/

MVMNTS_DIR	=		mvmnts/

UTILS_DIR	=		utils/

ALGORITHM_DIR	=	algorithm/

PUSH_SWAP	=		main.c

QUEUE	=			\
					$(addprefix $(QUEUE_DIR), \
					queueinit.c \
					queueadd.c \
					queuedel.c \
					queuepop.c \
					)

BTREE	=			\
					$(addprefix $(BTREE_DIR), \
					btreeinit.c \
					btreeadd.c \
					btreedel.c \
					bqueueinit.c \
					bqueueendequeue.c \
					bqueuedel.c \
					)

STACK	=			\
					$(addprefix $(STACK_DIR), \
					stackinit.c \
					stackpush.c \
					stackpop.c \
					stackdel.c \
					)

MVMNTS	=			\
					$(addprefix $(MVMNTS_DIR), \
					push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c \
					)

UTILS	=			\
					$(addprefix $(UTILS_DIR), \
					argtostack.c \
					)

ALGORITHM	= 	    \
					$(addprefix $(ALGORITHM_DIR), \
					threeelems.c \
					mergesort.c \
					algorithm_prep.c \
					the_algorithm.c \
					)

SRCS	= 			$(addprefix $(SRC_DIR), \
					$(QUEUE) \
					$(BTREE) \
					$(STACK) \
					$(MVMNTS) \
					$(UTILS) \
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
