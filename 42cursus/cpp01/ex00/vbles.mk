# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 22:49:11 by rgallego          #+#    #+#              #
#    Updated: 2023/09/29 16:05:19 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

EX00	=			\
					main.cpp \
					Zombie.cpp \
					newZombie.cpp \
					randomChump.cpp

SRCS	= 			$(addprefix $(SRC_DIR), \
						$(EX00) \
					)

OBJS	=			$(SRCS:.cpp=.o)

DPNDS	=			$(SRCS:.cpp=.d)

CC		=			c++

RM		=			-rm -f

CFLAGS	=			-Wall -Wextra -Werror -std=c++98

NAME	=			zombies

INC_ALL	=			\
					$(INC_DIR)
