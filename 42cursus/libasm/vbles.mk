SRC_DIR = 			src/

INC_DIR =			inc/

SRCS	=			\
					$(addprefix $(SRC_DIR), \
					ft_strlen.s \
					ft_strcpy.s \
					ft_strcmp.s \
					ft_write.s \
					ft_read.s \
					ft_strdup.s \
					)

SRCSBONUS	=		\
					$(addprefix $(SRC_DIR), \
					)

OBJS	=			$(SRCS:.c=.o)

OBJSBONUS	=		$(SRCSBONUS:.c=.o)

OBJSEXTRA	=		$(SRCSEXTRA:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

DPNDSBONUS	=		$(SRCSBONUS:.c=.d)

DPNDSEXTRA	=		$(SRCSEXTRA:.c=.d)

CC		=			gcc

RM		=			-rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra -MD

NAME	=			libasm.a
