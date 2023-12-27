# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 22:49:11 by rgallego          #+#    #+#              #
#    Updated: 2023/12/27 00:47:23 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

EX02	=			\
					main.cpp


SRCS	= 			$(addprefix $(SRC_DIR), \
						$(EX02) \
					)

OBJS	=			$(SRCS:.cpp=.o)

CC		=			c++

RM		=			-rm -f

CFLAGS	=			-Wall -Wextra -Werror -std=c++98

NAME	=			mutant_stack

INC_ALL	=			\
					$(INC_DIR)
