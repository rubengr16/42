-include vbles.mk

all: $(NAME)

$(NAME): $(OBJS) $(SRCH)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $^ -o $@

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

bonus: $(OBJSBONUS)
	$(AR) $(NAME) $(OBJSBONUS)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

.PHONY: all clean fclean bonus re so 
