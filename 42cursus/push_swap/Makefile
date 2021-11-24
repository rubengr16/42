SRCS =

QUEUE = 

SRCS += $(adprefix queue/, $(QUEUE))

SRCSBONUS	=		

SRCH	=			libft.h

OBJS	=			$(SRCS:.c=.o)

OBJSBONUS	=		$(SRCSBONUS:.c=.o)

CC		=			gcc

RM		=			rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra

NAME	=			push_swap	

LIBFT	=			libft/

LIBFTNAME =			libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 	

$(LIBFT)$(LIBFTNAME):
	$(MAKE) -C $(LIBFT) 

$(NAME): $(OBJS) $(LIBFT)$(LIBFTNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTNAME) -o $@
clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean 

re: fclean all

.PHONY: all clean fclean bonus re so 
