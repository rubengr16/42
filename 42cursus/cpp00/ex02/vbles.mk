# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 22:49:11 by rgallego          #+#    #+#              #
#    Updated: 2023/09/21 23:29:11 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

EX01	=			\
						Account.cpp \
						tests.cpp

SRCS	= 			$(addprefix $(SRC_DIR), \
						$(EX01) \
					)

OBJS	=			$(SRCS:.cpp=.o)

DPNDS	=			$(SRCS:.cpp=.d)

CC		=			c++

RM		=			-rm -f

CFLAGS	=			-Wall -Wextra -Werror -std=c++98

NAME	=			global_banksters_united

INC_ALL	=			\
					$(INC_DIR)
