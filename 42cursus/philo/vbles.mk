# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 16:19:28 by rgallego          #+#    #+#              #
#    Updated: 2023/02/26 20:54:17 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

PHILO	=			main.c

SRCS	= 			$(addprefix $(SRC_DIR), \
					$(PHILO) \
					utils.c \
					philo_queue.c \
					philosophare.c \
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			gcc

RM		=			-rm -f

CFLAGS	=			-Wall -Werror -Wextra -MD

NAME	=			philo

INC_ALL	=			\
					$(INC_DIR)
