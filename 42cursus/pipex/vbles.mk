SRC_DIR	=			src/

INC_DIR	=			inc/

CMDSLIST_DIR	=	cmdslist/


CMDSLIST	=		$(addprefix $(CMDSLIST_DIR), \
					cmdslist_init.c \
					cmdslist_push.c \
					cmdslist_pop.c \
					cmdslist_del.c \
					)

SRCS	= 			$(addprefix $(SRC_DIR), \
					main.c \
					utils.c \
					pipex.c \
					$(CMDSLIST) \
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			gcc

RM		=			-rm -f

CFLAGS	=			-Wall -Werror -Wextra -MD

LDFLAGS	=			$(LIBFTNAME)

NAME	=			pipex

INC_ALL	=			\
					$(INC_DIR) \
					$(LIBFT)$(INC_DIR)

LIBFT	=			libft/

LIBFTNAME =			$(LIBFT)libft.a
