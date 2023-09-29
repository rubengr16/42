# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 22:49:11 by rgallego          #+#    #+#              #
#    Updated: 2023/09/29 17:58:13 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

EX03	=			\
					main.cpp \
					Weapon.cpp \
					HumanA.cpp \
					HumanB.cpp

SRCS	= 			$(addprefix $(SRC_DIR), \
						$(EX03) \
					)

OBJS	=			$(SRCS:.cpp=.o)

DPNDS	=			$(SRCS:.cpp=.d)

CC		=			c++

RM		=			-rm -f

CFLAGS	=			-Wall -Wextra -Werror -std=c++98

NAME	=			violence

INC_ALL	=			\
					$(INC_DIR)
