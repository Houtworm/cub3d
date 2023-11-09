# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: houtworm <codam@houtworm.net>                +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/26 10:46:29 by houtworm      #+#    #+#                  #
#    Updated: 2023/11/09 09:17:26 by houtworm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=cub3d
CC			=gcc
FC			=-Wall -Werror -Wextra -Wunreachable-code -flto -Ofast -march=native -g #-fsanitize=address
HEAD		=-I ./include -I $(MLX)/include
RM			=rm -rf
LIB			=libft/libft.a getnextline/get_next_line.a mlx/build/libmlx42.a -ldl -lglfw -pthread -lm
SRC			=src/main/main.c\
			 src/main/pickup.c\
			 src/main/init.c\
			 src/main/error.c\
			 src/main/cleanup.c\
			 src/main/bullet.c\
			 src/main/fire.c\
			 src/main/enemy.c\
			 src/main/minimap.c\
			 src/main/finish.c\
			 src/main/interact.c\
			 src/parse/parse.c\
			 src/parse/map.c\
			 src/parse/sprite.c\
			 src/parse/flood.c\
			 src/draw/raycast.c\
			 src/draw/world.c\
			 src/draw/texture.c\
			 src/draw/weapon.c\
			 src/draw/stats.c\
			 src/input/game.c\
			 src/input/move.c\
			 src/input/turn.c\
			 src/input/rest.c\
			 src/sprite/check.c\
			 src/sprite/draw.c
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
