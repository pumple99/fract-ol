# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2023/01/06 20:25:43 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Werror -Wall -Wextra
DEBUG_FLAGS = -g
LIB = libft.a
LIB_DIR = ./libft

SRCS_C = exit.c input.c input2.c operation.c stack.c
SRCS_M = main.c sort.c trisection.c pile.c pile2.c
SRCS_B = main_bonus.c

OBJS_C = $(SRCS_C:.c=.o)
OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
DEPS = $(OBJS_C:.o=.d) $(OBJS_B:.o=.d) $(OBJS_M:.o=.d) $(BONUS).d $(NAME).d

$(NAME) :: $(LIB)
$(NAME) :: $(OBJS_M) $(OBJS_C)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -MMD -o $(NAME) $^ $(LIB) $(DEBUG_FLAGS)

all : $(NAME)

bonus : $(BONUS)

$(BONUS) :: $(LIB)
$(BONUS) :: $(OBJS_B) $(OBJS_C)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -MMD -o $(BONUS) $^ $(LIB) $(DEBUG_FLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c -I. -MMD $< $(DEBUG_FLAGS)

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS_C) $(OBJS_B) $(OBJS_M) $(LIB) $(DEPS)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(BONUS)

re :
	make fclean
	make all

ifeq "$(filter clean fclean re,$(MAKECMDGOALS))" ""
-include $(DEPS)
endif

.PHONY : clean fclean re
