-include vbles.mk

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $^ -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

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
