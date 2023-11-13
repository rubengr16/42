# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 22:49:11 by rgallego          #+#    #+#              #
#    Updated: 2023/11/11 12:24:30 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

EX02	=			\
					main.cpp \
					Fixed.cpp

SRCS	= 			$(addprefix $(SRC_DIR), \
						$(EX02) \
					)

OBJS	=			$(SRCS:.cpp=.o)

CC		=			c++

RM		=			-rm -f

CFLAGS	=			-Wall -Wextra -Werror -std=c++98

NAME	=			fixed_talking

INC_ALL	=			\
					$(INC_DIR)
