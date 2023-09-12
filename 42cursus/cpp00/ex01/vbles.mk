# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 22:49:11 by rgallego          #+#    #+#              #
#    Updated: 2023/09/12 23:52:10 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

EX01	=			\
						Contact.cpp \
						PhoneBook.cpp \

SRCS	= 			$(addprefix $(SRC_DIR), \
						$(EX01) \
					)

OBJS	=			$(SRCS:.cpp=.o)

DPNDS	=			$(SRCS:.cpp=.d)

CC		=			g++

RM		=			-rm -f

CFLAGS	=			-Wall -Wextra -Werror -std=c++98

NAME	=			phonebook

INC_ALL	=			\
					$(INC_DIR)
