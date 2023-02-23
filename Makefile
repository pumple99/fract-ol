# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2023/02/21 18:37:00 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS = fractol_bonus
CC = cc
CFLAGS = -Werror -Wall -Wextra
DEBUG_FLAGS = -g
LIB = libft.a
LIB_DIR = ./libft
MLX_DIR = ./mlx
SRCS_DIR = ./srcs
OBJ_DEPS_DIR = ./obj_deps

SRCS_C = input.c hook.c draw.c color.c
SRCS_M = main.c print.c draw_man.c input_man.c
SRCS_B = main_bonus.c print_bonus.c draw_bonus.c input_bonus.c color_bonus.c

OBJS_C = $(SRCS_C:.c=.o)
OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
DEPS = $(OBJS_C:.o=.d) $(OBJS_B:.o=.d) $(OBJS_M:.o=.d) $(BONUS).d $(NAME).d

$(NAME) :: $(LIB)
$(NAME) :: $(OBJS_M) $(OBJS_C)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -I$(MLX_DIR) -Lmlx -lmlx -framework OpenGL \
	-framework AppKit -MMD -o $(NAME) $^ $(LIB) $(DEBUG_FLAGS)

all : $(NAME)

bonus : $(BONUS)

$(BONUS) :: $(LIB)
$(BONUS) :: $(OBJS_B) $(OBJS_C)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -I$(MLX_DIR) -Lmlx -lmlx -framework OpenGL \
	-framework AppKit -MMD -o $(BONUS) $^ $(LIB) $(DEBUG_FLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c -MMD $< $(DEBUG_FLAGS)

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
