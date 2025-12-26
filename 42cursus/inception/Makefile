# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 09:48:21 by rgallego          #+#    #+#              #
#    Updated: 2025/12/26 11:57:28 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include vbles.mk

all: up

up:
	$(COMPOSE_CMD) up $(DETACH)

up-detachless:
	$(MAKE) DL=1

down:
	$(COMPOSE_CMD) down

build:
	$(COMPOSE_CMD) build --no-cache

exec:
	$(COMPOSE_CMD) exec -it $(SERVICE) sh

ps:
	$(COMPOSE_CMD) ps $(PS_ALL)

logs:
	$(COMPOSE_CMD) $(LOGS_CMD) $(SERVICE) $(EXEC_CMD) $(LOG_FILE)

clean: down
	sudo $(RM) -rf $(MARIADB_DATA)
	sudo $(RM) -rf $(WORDPRESS_HTML)

fclean: clean

re: fclean build all

.PHONY: all clean fclean re up up-detachless down build ps logs
