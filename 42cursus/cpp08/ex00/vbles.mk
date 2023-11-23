# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 22:49:11 by rgallego          #+#    #+#              #
#    Updated: 2023/11/23 18:28:58 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

EX00	=			\
					main.cpp


SRCS	= 			$(addprefix $(SRC_DIR), \
						$(EX00) \
					)

OBJS	=			$(SRCS:.cpp=.o)

CC		=			c++

RM		=			-rm -f

CFLAGS	=			-Wall -Wextra -Werror -std=c++98

NAME	=			easyfind

INC_ALL	=			\
					$(INC_DIR)
