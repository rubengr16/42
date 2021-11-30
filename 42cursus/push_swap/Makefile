-include vbles.mk

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
