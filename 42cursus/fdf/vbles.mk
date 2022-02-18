SRC_DIR	=			src/

INC_DIR	=			inc/


SRCS	= 			$(addprefix $(SRC_DIR), \
					\
					\
					\
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			gcc

RM		=			-rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra -MD

LDFLAGS	=			$(LIBFTNAME) \
					$(GNLNAME)

NAME	=			fdf

INC_ALL	=			\
					$(INC_DIR) \
					$(LIBFT)$(INC_DIR)

LIBFT	=			libft/

LIBFTNAME =			$(LIBFT)libft.a

GNL		=			get_next_line/

GNLNAME	=			get_next_line
