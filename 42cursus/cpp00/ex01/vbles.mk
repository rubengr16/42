# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 22:49:11 by rgallego          #+#    #+#              #
#    Updated: 2023/09/08 22:29:27 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

EX00	=			megaphone.cpp

SRCS	= 			$(addprefix $(SRC_DIR), \
						$(EX00) \
					)

OBJS	=			$(SRCS:.cpp=.o)

DPNDS	=			$(SRCS:.cpp=.d)

CC		=			g++

RM		=			-rm -f

CFLAGS	=			-Wall -Wextra -Werror -std=c++98

NAME	=			megaphone

INC_ALL	=			\
					$(INC_DIR)
