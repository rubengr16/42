# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 16:21:03 by rgallego          #+#    #+#              #
#    Updated: 2023/02/22 17:08:12 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include vbles.mk

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INC_ALL)) -c $< -o $@

$(LIBFTNAME):
	$(MAKE) -C $(LIBFT)

$(GNLNAME):
	$(MAKE) -C $(GNL)

$(NAME): $(OBJS) $(LIBFTNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTNAME) -o $@

bonus: $(OBJSBONUS) $(LDFLAGS) $(LDFLAGSBONUS)
	$(CC) $(CFLAGS) $(OBJSBONUS) $(LDFLAGS) $(LDFLAGSBONUS) -o $(CHECKER)

clean:
	$(RM) $(OBJS) $(DPNDS) $(OBJSBONUS) $(DPNDSBONUS) $(CHECKER)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(GNL) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
