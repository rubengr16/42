# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vbles.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgallego <rgallego@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 16:19:28 by rgallego          #+#    #+#              #
#    Updated: 2023/02/22 20:45:25 by rgallego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=			src/

INC_DIR	=			inc/

QUEUE_DIR	=		queue/

STACK_DIR	=		stack/

MVNTSLIST_DIR	=	mvntslist/

MVNTS_DIR	=		mvnts/

ALGORITHM_DIR	=	algorithm/

BONUS_DIR	=		bonus/

PUSH_SWAP	=		main.c

QUEUE	=			\
					$(addprefix $(QUEUE_DIR), \
					queueinit.c \
					queueadd.c \
					queuedel.c \
					queuepop.c \
					)

STACK	=			\
					$(addprefix $(STACK_DIR), \
					snodeutils.c \
					stackinit.c \
					stackpush.c \
					stackpop.c \
					stackdel.c \
					)

MVNTSLIST	=		\
					$(addprefix $(MVNTSLIST_DIR), \
					mvntslistinit.c \
					mvntslistadd.c \
					mvntslistpop.c \
					mvntslistdel.c \
					)

MVNTS	=			\
					$(addprefix $(MVNTS_DIR), \
					push.c \
					rev_rotate.c \
					rotate.c \
					swap.c \
					)

UTILS	=			utils.c

ALGORITHM	= 	    \
					$(addprefix $(ALGORITHM_DIR), \
					merge_mdn.c \
					order_a.c \
					order_b.c \
					prep.c \
					utils.c \
					optimizer.c \
					optimize_r.c \
					)

BONUS	=			\
					$(addprefix $(BONUS_DIR), \
					checker_bonus.c \
					utils_bonus.c \
					)

SRCS	= 			$(addprefix $(SRC_DIR), \
					$(QUEUE) \
					$(STACK) \
					$(MVNTS) \
					$(MVNTSLIST) \
					$(UTILS) \
					$(ALGORITHM) \
					$(PUSH_SWAP) \
					)

SRCSBONUS	=		$(addprefix $(SRC_DIR), \
					$(QUEUE) \
					$(STACK) \
					$(MVNTS) \
					$(MVNTSLIST) \
					$(UTILS) \
					$(BONUS)\
					)

OBJS	=			$(SRCS:.c=.o)

OBJSBONUS	=		$(SRCSBONUS:.c=.o)

DPNDS	=			$(SRCS:.c=.d)

DPNDSBONUS	=		$(SRCSBONUS:.c=.d)

CC		=			gcc

RM		=			-rm -f

CFLAGS	=			-Wall -Werror -Wextra -MD

LDFLAGS	=			$(LIBFTNAME)

LDFLAGSBONUS	=	$(GNLNAME)

NAME	=			push_swap

CHECKER	=			checker

INC_ALL	=			\
					$(INC_DIR) \
					$(LIBFT)$(INC_DIR) \
					$(GNL)$(INC_DIR)

LIBFT	=			libft/

LIBFTNAME	=		$(LIBFT)libft.a

GNL		=			get_next_line/

GNLNAME	=			$(GNL)get_next_line.a
