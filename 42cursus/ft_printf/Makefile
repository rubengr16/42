PRINTF	=			ft_printf.c

SRCS	=			ft_printf_chr.c \
					ft_printf_str.c \
					ft_printf_ptr.c \
					ft_printf_int.c \
					ft_printf_uns.c \
					ft_printf_hex.c \
					ft_printf_hexup.c \
					ft_putnbr_base.c

SRCSBONUS	=		ft_printf_bonus.c \
					ft_printf_minus_bonus.c \
					ft_printf_sharp_bonus.c \
					ft_printf_space_bonus.c \
					ft_printf_plus_bonus.c \
					ft_width_bonus.c \
					ft_strutils_bonus.c

SRCH	=			libftprintf.h

SRCHBONUS	=		libftprintf_bonus.h

OBJSPRINTF	=		$(PRINTF:.c=.o)

OBJS	=			$(SRCS:.c=.o)

OBJSBONUS	=		$(SRCSBONUS:.c=.o)

CC		=			gcc

RM		=			rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			libftprintf.a


all: $(NAME)

$(NAME): $(OBJSPRINTF) $(OBJS) $(SRCH)
	$(AR) $(NAME) $(OBJSPRINTF) $(OBJS)

clean:
	$(RM) $(OBJSPRINTF) $(OBJS)  $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

bonus: $(OBJS) $(OBJSBONUS) $(SRCHBONUS)
	$(AR) $(NAME) $(OBJS) $(OBJSBONUS)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(PRINTF) $(SRCS) $(SRCSBONUS)
	gcc -nostartfiles -shared -o libftprintf.so $(OBJSPRINTF) $(OBJS) $(OBJSBONUS)

.PHONY: all clean fclean bonus re so 
