# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: houtworm <codam@houtworm.net>                +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/26 10:46:29 by houtworm      #+#    #+#                  #
#    Updated: 2023/11/10 05:30:35 by houtworm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=cub3d
CC			=gcc
FC			=-Wall -Werror -Wextra -Wunreachable-code -flto -Ofast -march=native# -g -fsanitize=address
HEAD		=-I ./include -I $(MLX)/include
RM			=rm -rf
LIB			=libft/libft.a getnextline/get_next_line.a mlx/build/libmlx42.a -ldl -lglfw -pthread -lm
SRC			=src/main/main.c\
			 src/main/init.c\
			 src/main/raycast.c\
			 src/main/error.c\
			 src/main/cleanup.c\
			 src/action/fire.c\
			 src/action/enemy.c\
			 src/action/pickup.c\
			 src/action/interact.c\
			 src/parse/cubfile.c\
			 src/parse/map.c\
			 src/parse/sprite.c\
			 src/parse/flood.c\
			 src/draw/world.c\
			 src/draw/texture.c\
			 src/draw/minimap.c\
			 src/draw/weapon.c\
			 src/draw/stats.c\
			 src/draw/flash.c\
			 src/draw/menu.c\
			 src/input/game.c\
			 src/input/move.c\
			 src/input/turn.c\
			 src/input/acro.c\
			 src/input/mouse.c\
			 src/sprite/check.c\
			 src/sprite/sprite.c
OBJ			=$(SRC:src/%.c=obj/%.o)

all:		libft getnextline mlx/build/mlx42.a $(NAME)

clean:
				@$(RM) obj
				@$(MAKE) -C libft clean > /dev/null
				@$(MAKE) -C getnextline clean > /dev/null
				@$(MAKE) -C mlx/build clean > /dev/null
				@printf "\e[1;35mCleaned Object Files\n\e[0;00m"

fclean:		clean
				@$(RM) $(NAME) mlx/build > /dev/null
				@$(MAKE) -C libft fclean > /dev/null
				@$(MAKE) -C getnextline fclean > /dev/null
				@printf "\e[1;31mCleaned Executables\n\e[0;00m"

re:			fclean all

$(OBJ):		$(SRC) Makefile cub3d.h
				@mkdir -p $(dir $@)
				@printf "\e[1;34mBuilding $@\n\e[0;00m"
				@$(CC) $(CFLAGS) -c $(@:obj/%.o=src/%.c) -o $@

$(NAME):	$(OBJ)
				@printf "\e[1;36mCompiling $@\e[0;00m\n"
				@$(CC) $(FC) -o $(NAME) $(SRC) $(LIB) $(HEAD)
				@printf "\e[1;32mDone\e[0;00m\n"

libft:
				@$(MAKE) -C libft all

getnextline:
				@$(MAKE) -C getnextline all

mlx/build/mlx42.a:
				@cmake -S mlx -B mlx/build
				@$(MAKE) -C mlx/build -j4

.PHONY: libft getnextline
