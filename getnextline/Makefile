# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                           :+:    :+:             #
#                                                    |:_/ || |_ _   ___  __    #
#    By: djonker <djonker@student.codam.nl>         //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2021/05/27 01:24:02 by djonker      /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2023/10/26 18:00:26 by houtworm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=get_next_line.a
CC			=gcc
FC			=-Wall -Werror -Wextra
RM			=rm -f
SRC			=src/get_next_line.c\
			src/get_next_line_utils.c
OBJ			=$(SRC:src/%.c=obj/%.o)
FAR			=ar -crs

all:		$(NAME)

bonus:		$(NAME)

clean:
				@$(RM) -r obj
				@printf "\e[1;35mCleaned Object Files\n\e[0;00m"

fclean:		clean
				@$(RM) $(NAME)
				@printf "\e[1;31mCleaned Executables\n\e[0;00m"

re:			fclean all

$(OBJ):		$(SRC) get_next_line.h Makefile
				@mkdir -p $(dir $@)
				@printf "\e[1;34mBuilding $@\n\e[0;00m"
				@$(CC) $(CFLAGS) -c $(@:obj/%.o=src/%.c) -o $@

$(NAME):	$(OBJ)
				@printf "\e[1;36mCompiling get next line\e[0;00m\n"
				@$(FAR) $(NAME) $^ > /dev/null 2>&1
				@printf "\e[1;32mDone\e[0;00m\n"
