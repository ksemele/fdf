# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghael <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 12:33:38 by cghael            #+#    #+#              #
#    Updated: 2020/02/13 12:33:40 by cghael           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)includes/

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./minilibx_o/
MINILIBX_HEADERS = $(MINILIBX_DIR)

HEADERS_LIST = fdf.h \
				keys.h

HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = ./src/
SRC_LIST = main.c \
				ft_check_args.c \
				ft_error_print.c \
				ft_create_t_mlx.c \
				ft_draw_line.c \
				ft_draw_img_line.c \
				ft_fisbigger.c \
				ft_fabsf.c \
				ft_check_line_points.c \
				ft_draw_wireframe.c \
				ft_draw_img_wireframe.c \
				ft_increase_point_size.c \
				ft_atoi_base.c \
				ft_isometric.c \
				ft_draw_img_background.c \
				ft_slide_x.c \
				ft_slide_y.c \
				ft_deal_key.c \
				ft_read_points_to_struct.c \
				ft_img_isometric.c \
				ft_controls.c \
				ft_mouse_move.c \
				ft_mouse_press.c \
				ft_mouse_release.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "\n$(NAME): $(GRN)*.o files created$(END)"
	@echo "$(NAME): $(GRN)$(NAME) created$(END)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GRN)$(OBJ_DIR) created$(END)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS) $(LIBFT_HEADERS)libft.h $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GRN).$(END)\c"

$(LIBFT):
	@echo "$(NAME): $(GRN)Creating $(LIBFT)...$(END)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX):
	@echo "$(NAME): $(GRN)Creating $(MINILIBX)...$(END)"
	@$(MAKE) -sC $(MINILIBX_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) deleted$(END)"
	@echo "$(NAME): $(RED)*.o files deleted$(END)"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) deleted$(END)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) deleted$(END)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) deleted$(END)"

re:
	@$(MAKE) fclean
	@$(MAKE) all