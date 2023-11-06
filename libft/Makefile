# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: djonker <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 15:02:02 by djonker       #+#    #+#                  #
#    Updated: 2023/10/26 18:29:23 by houtworm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=libft.a
CC			=gcc
FC			=-Wall -Werror -Wextra# -g -fsanitize=address
FAR			=ar -rs
RM			=rm -f
SRC			=src/ft_atoi.c \
			src/ft_bzero.c \
			src/ft_calloc.c \
			src/ft_cntwrd.c \
			src/ft_intlen.c \
			src/ft_isalnum.c \
			src/ft_isalpha.c \
			src/ft_isascii.c \
			src/ft_isdigit.c \
			src/ft_isprint.c \
			src/ft_itoa.c \
			src/ft_malstr.c \
			src/ft_memccpy.c \
			src/ft_memchr.c \
			src/ft_memcmp.c \
			src/ft_memmove.c \
			src/ft_memcpy.c \
			src/ft_memset.c \
			src/ft_putchar_fd.c \
			src/ft_putendl_fd.c \
			src/ft_putnbr_fd.c \
			src/ft_putstr_fd.c \
			src/ft_split.c \
			src/ft_strchr.c \
			src/ft_strdup.c \
			src/ft_strjoin.c \
			src/ft_strlcat.c \
			src/ft_strlcpy.c \
			src/ft_strlen.c \
			src/ft_strmapi.c \
			src/ft_strncmp.c \
			src/ft_strnstr.c \
			src/ft_strrchr.c \
			src/ft_strtrim.c \
			src/ft_substr.c \
			src/ft_tolower.c \
			src/ft_toupper.c \
			src/ft_wrdlen.c \
			src/ft_frenarr.c \
			src/ft_btoi.c \
			src/ft_itob.c \
			src/ft_revstr.c \
			src/ft_frearr.c \
			src/ft_putznbr.c \
			src/ft_strupp.c \
			src/ft_strlow.c \
			src/ft_power.c \
			src/ft_sqrt.c \
			src/ft_factor.c \
			src/ft_fnprim.c \
			src/ft_isprim.c \
			src/ft_dtoh.c \
			src/ft_htod.c \
			src/ft_htoi.c \
			src/ft_itoh.c \
			src/ft_ddtoi.c \
			src/ft_itodd.c \
			src/ft_otoi.c \
			src/ft_itoo.c \
			src/ft_swap.c \
			src/ft_swaplong.c \
			src/ft_round.c \
			src/ft_putznbr_fd.c \
			src/ft_putzflo_fd.c \
			src/ft_putzflo.c \
			src/ft_putstr.c \
			src/ft_putnbr.c \
			src/ft_putnbr_base.c \
			src/ft_putflo.c \
			src/ft_putendl.c \
			src/ft_putchar.c \
			src/ft_linlen.c \
			src/ft_itof.c \
			src/ft_isneg.c \
			src/ft_iftof.c \
			src/ft_ftoi.c \
			src/ft_ftoa.c \
			src/ft_fround.c \
			src/ft_flolen.c \
			src/ft_declen.c \
			src/ft_atof.c \
			src/ft_putflo_fd.c \
			src/ft_arrlen.c \
			src/ft_chrstr.c \
			src/ft_cntwrds.c \
			src/ft_isodigit.c \
			src/ft_isxdigit.c \
			src/ft_malstrs.c \
			src/ft_min.c \
			src/ft_max.c \
			src/ft_lincpy.c \
			src/ft_linlcpy.c \
			src/ft_splits.c \
			src/ft_wrdlens.c \
			src/ft_vamin.c \
			src/ft_vamax.c \
			src/ft_islowc.c \
			src/ft_isuppc.c \
			src/ft_bitswap.c \
			src/ft_itozh.c \
			src/ft_itoba.c \
			src/ft_itohx.c \
			src/ft_cntchr.c \
			src/ft_cntarg.c \
			src/ft_around.c \
			src/ft_putzsci.c \
			src/ft_putull.c \
			src/ft_putlong.c \
			src/ft_ltoa.c \
			src/ft_utoa.c \
			src/ft_atou.c \
			src/ft_atol.c \
			src/ft_putzscih.c \
			src/ft_luilen.c \
			src/ft_itooa.c \
			src/ft_dtoa.c \
			src/ft_atodec.c \
			src/ft_fczero.c \
			src/ft_lftoi.c \
			src/ft_lftoa.c \
			src/ft_islneg.c \
			src/ft_ldeclen.c \
			src/ft_isallbyte.c \
			src/ft_getuser.c \
			src/ft_gethome.c \
			src/ft_getpwd.c \
			src/ft_vastrjoin.c \
			src/ft_vafree.c \
			src/ft_intrchr.c \
			src/ft_system.c \
			src/ft_getpaths.c \
			src/ft_getenvval.c \
			src/ft_seminit.c \
			src/ft_semwait.c \
			src/ft_semfree.c \
			src/ft_gettimemsdate.c \
			src/ft_mkdir.c \
			src/ft_rmdir.c \
			src/ft_abspathcmd.c \
			src/ft_cppbzero.c \
			src/ft_cpptostr.c
BSRC		=src/ft_lstadd_back.c \
			src/ft_lstadd_front.c \
			src/ft_lstclear.c \
			src/ft_lstdelone.c \
			src/ft_lstiter.c \
			src/ft_lstlast.c \
			src/ft_lstmap.c \
			src/ft_lstnew.c \
			src/ft_lstsize.c
OBJ			=$(SRC:src/%.c=obj/%.o)
BOBJ		=$(BSRC:src/%.c=obj/%.o)

ifdef WITBON
COBJ		=$(OBJ) $(BOBJ)
CSRC		=$(SRC) $(BSRC)
else
COBJ		=$(OBJ)
CSRC		=$(SRC)
endif

all:		$(NAME)

clean:
				@$(RM) -r obj
				@printf "\e[1;35mCleaned Object Files\n\e[0;00m"

fclean:		clean
				@$(RM) $(NAME)
				@printf "\e[1;31mCleaned Executables\n\e[0;00m"

re:			fclean all

$(COBJ):	$(CSRC)
				@mkdir -p $(dir $@)
				@printf "\e[1;34mBuilding $@\n\e[0;00m"
				@$(CC) $(CFLAGS) -c $(@:obj/%.o=src/%.c) -o $@

$(NAME):	$(COBJ)
				@printf "\e[1;36mCompiling $@\e[0;00m\n"
				@$(FAR) $(NAME) $^ > /dev/null 2>&1
				@printf "\e[1;32mDone\e[0;00m\n"

bonus:
				@$(MAKE) WITBON=1 all
