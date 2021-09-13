SRCS	=			ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_strlen.c \
					ft_memset.c \
					ft_memcpy.c \
					ft_toupper.c \
					ft_tolower.c

SRCH	=			libft.h

OBJS	=			$(SRCS:.c=.o)

CC		=			gcc

RM		=			rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			libft.a


all: $(NAME)

$(NAME): $(OBJS) $(SRCH)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

bonus: $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean bonus re so 
