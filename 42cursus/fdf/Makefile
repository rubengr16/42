# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 19:08:09 by rgallego          #+#    #+#              #
#    Updated: 2022/03/07 16:29:49 by rgallego         ###   ########.fr        #
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

$(MLXNAME):
	$(MAKE) -C $(MLX)

$(NAME): $(OBJS) $(LDFLAGS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(FRAMEWORK) -o $@

clean:
	$(RM) $(OBJS) $(DPNDS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean 
	$(MAKE) -C $(GNL) fclean
	$(MAKE) -C $(MLX) clean

re: fclean all

.PHONY: all clean fclean re
