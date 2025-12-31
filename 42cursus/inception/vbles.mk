# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 09:59:14 by rgallego          #+#    #+#              #
#    Updated: 2025/12/30 20:56:53 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR				=	srcs/

REQS_DIR			=	requirements/

MARIADB_DIR			=	mariadb/

MARIADB_DATA		=	$(SRC_DIR)$(REQS_DIR)$(MARIADB_DIR)data

MARIADB_LOGFILE		=	/data/*.err

WORDPRESS_DIR		=	wordpress/

WORDPRESS_HTML		=	$(SRC_DIR)$(REQS_DIR)$(WORDPRESS_DIR)html

PHP_FPM_LOGFILE		=	/var/log/php83/error.log

NGINX_DIR			=	nginx/

NGINX_LOGFILE		=	/var/log/nginx/error.log

COMPOSE_FILE 		=	docker-compose.yml

COMPOSE_CMD	=	docker compose -f $(SRC_DIR)$(COMPOSE_FILE)

DETACH				=	-d
ifeq ($(strip $(or $(DL),$(DETACHLESS))),1)
	DETACH			=
endif

PS_ALL				:=
ifeq ($(strip $(PS_A)),1)
	PS_ALL			:=	-a
endif

SERVICE				:=	$(strip $(or $(S),$(SERVICE)))
ifeq ($(SERVICE), )
	SERVICE			=	mariadb
endif
LOGS_CMD			=	logs
EXEC_CMD			=	
LOG_FILE				:=	$(strip $(or $(F),$(LOGFILE)))
ifeq ($(LOGFILE), 1)
	LOGS_CMD		=	exec
	EXEC_CMD		=	cat
	ifeq ($(SERVICE), wordpress)
		LOG_FILE		=	$(PHP_FPM_LOGFILE)
	else ifeq ($(strip $(SERVICE)),nginx)
		LOG_FILE		=	$(NGINX_LOGFILE)
	else
		SERVICE			=	mariadb
		EXEC_CMD		=	sh -c "cat 
		LOG_FILE		=	$(MARIADB_LOGFILE)"
	endif
endif