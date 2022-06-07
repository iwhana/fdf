# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 00:30:47 by iwhana            #+#    #+#              #
#    Updated: 2022/04/19 23:38:44 by iwhana21         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = draw.c fdf.c read_map.c fdf_utils.c
OBJ = $(SRC:%.c=%.o)
HEADER = fdf.h
 
# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
 
# mlx library
MLX = ./minilibx_macos/
MLX_LIB = $(addprefix $(MLX),mlx.a)
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit
 
# ft library
FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft
 
all: $(FT_LIB) $(MLX_LIB) $(NAME)
 
%.o: %.c $(HEADER) ./libft/libft.h
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(HEADER) -c $< -o $@
 
$(FT_LIB): ./libft/libft.h
	make -C $(FT)
 
$(MLX_LIB):
	make -C $(MLX)
 
$(NAME): $(OBJ) $(HEADER) 
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
 
clean:
	rm -rf $(OBJ)
	make -C $(FT) clean
	make -C $(MLX) clean
 
fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
 
re: fclean all
