# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 19:07:43 by rgallego          #+#    #+#              #
#    Updated: 2022/03/07 11:35:27 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/


SRCS	= 			$(addprefix $(SRC_DIR), \
					main.c \
					utils.c \
					parser.c \
					)

OBJS	=			$(SRCS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

CC		=			gcc

RM		=			-rm -f

AR		=			ar rcs

CFLAGS	=			-Wall -Werror -Wextra -MD

LDFLAGS	=			$(LIBFTNAME) \
					$(GNLNAME)

NAME	=			fdf

INC_ALL	=			\
					$(INC_DIR) \
					$(LIBFT)$(INC_DIR) \
					$(GNL)$(INC_DIR)					

LIBFT	=			libft/

LIBFTNAME =			$(LIBFT)libft.a

GNL		=			get_next_line/

GNLNAME	=			$(GNL)get_next_line.a
