# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 15:20:31 by seunghoy          #+#    #+#              #
#    Updated: 2023/02/24 15:46:23 by seunghoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
BONUS := fractol_bonus
CC := cc
CFLAGS := -Werror -Wall -Wextra
DEBUG_FLAGS := -g
LIB := libft.a
LIB_DIR := libft
MLX_DIR := mlx
SRCS_DIR := srcs
OBJS_DIR := objs

CHANGABLE_HEADERS = fractal.h

SRCS_C := $(addprefix $(SRCS_DIR)/, input.c hook.c draw.c color.c)
SRCS_M := $(addprefix $(SRCS_DIR)/, main.c print.c draw_man.c input_man.c)
SRCS_B := $(addprefix $(SRCS_DIR)/, main_bonus.c print_bonus.c \
draw_bonus.c input_bonus.c color_bonus.c)

OBJS_C := $(SRCS_C:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_M := $(SRCS_M:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_B := $(SRCS_B:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

$(NAME) :: $(LIB)
$(NAME) :: $(OBJS_M) $(OBJS_C) $(CHANGABLE_HEADERS)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -I$(MLX_DIR) -Lmlx -lmlx -framework OpenGL \
	-framework AppKit $(OBJS_M) $(OBJS_C) $(LIB) $(DEBUG_FLAGS) -o $(NAME)

all : $(NAME)

bonus : $(BONUS)

$(BONUS) :: $(LIB)
$(BONUS) :: $(OBJS_B) $(OBJS_C) $(CHANGABLE_HEADERS)
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -I$(MLX_DIR) -Lmlx -lmlx -framework OpenGL \
	-framework AppKit $(OBJS_B) $(OBJS_C) $(LIB) $(DEBUG_FLAGS) -o $(BONUS)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< $(DEBUG_FLAGS) -o $@

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

$(CHANGABLE_HEADERS) :

clean :
	make -C $(LIB_DIR) clean
	rm -rf $(OBJS_C) $(OBJS_B) $(OBJS_M) $(LIB)

fclean : clean
	make -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(BONUS)

re :
	make fclean
	make all

.PHONY : clean fclean re
