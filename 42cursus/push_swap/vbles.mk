SRC_DIR	=			src/

INC_DIR	=			inc/

QUEUE_DIR	=		queue/

STACK_DIR	=		stack/

MVNTSLIST_DIR	=	mvntslist/

MVMNTS_DIR	=		mvmnts/

ALGORITHM_DIR	=	algorithm/

PUSH_SWAP	=		main.c

QUEUE	=			\
					$(addprefix $(QUEUE_DIR), \
					queueinit.c \
					queueadd.c \
					queuedel.c \
					queuepop.c \
					)

STACK	=			\
					$(addprefix $(STACK_DIR), \
					stackinit.c \
					stackpush.c \
					stackpop.c \
					stackdel.c \
					)

MVNTSLIST	=		\
					$(addprefix $(MVNTSLIST_DIR), \
					mvntslistinit.c \
					mvntslistadd.c \
					mvntslistpop.c \
					mvntslistdel.c \
					)

MVMNTS	=			\
					$(addprefix $(MVMNTS_DIR), \
					push.c \
					reverse_rotate.c \
					rotate.c \
					swap.c \
					)

UTILS	=			utils.c

ALGORITHM	= 	    \
					$(addprefix $(ALGORITHM_DIR), \
					threeelems.c \
					merge_mdn.c \
					prep.c \
					utils.c \
					optimizer.c \
					)

SRCS	= 			$(addprefix $(SRC_DIR), \
					$(QUEUE) \
					$(STACK) \
					$(MVNTSLIST) \
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
