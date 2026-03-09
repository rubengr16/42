# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 16:19:28 by rgallego          #+#    #+#              #
#    Updated: 2024/10/10 17:13:19 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

UTILS_DIR	=		utils/

INC_DIR	=			inc/

FT_SSL	=			main.c

UTILS	=			$(addprefix $(UTILS), \
					utils.c
					)

SRCS	= 			$(addprefix $(SRC_DIR), \
					$(FT_SSL) \
					$(UTILS)
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			gcc

RM		=			-rm -f

CFLAGS	=			-Wall -Werror -Wextra -MD

NAME	=			ft_ssl

INC_ALL	=			\
					$(INC_DIR)
