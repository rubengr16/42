SRCS	=			ft_printf.c \
					ft_printf_chr.c \
					ft_printf_str.c \
					ft_printf_ptr.c \
					ft_printf_int.c \
					ft_printf_uns.c \
					ft_printf_hex.c \
					ft_printf_hexup.c \
					ft_putnbr_base.c
#SRCSBONUS	=		

SRCH	=			libftprintf.h

OBJS	=			$(SRCS:.c=.o)

#OBJSBONUS	=		$(SRCSBONUS:.c=.o)

CC		=			gcc

RM		=			rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			libftprintf.a


all: $(NAME)

$(NAME): $(OBJS) $(SRCH)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)       #     $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

#bonus: $(OBJSBONUS)
#	$(AR) $(NAME) $(OBJSBONUS)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libftprintf.so $(OBJS)

.PHONY: all clean fclean bonus re so 
