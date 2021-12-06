-include vbles.mk

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INC_ALL)) -c $< -o $@

$(LIBFTNAME):
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFTNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTNAME) -o $@

clean:
	$(RM) $(OBJS) $(DPNDS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean 

re: fclean all

-include $(SRCS:.c=.d)

.PHONY: all clean fclean bonus re
