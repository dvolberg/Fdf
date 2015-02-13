# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvolberg <dvolberg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/14 15:15:08 by dvolberg          #+#    #+#              #
#    Updated: 2015/02/06 14:43:16 by dvolberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

LX11 = -L/usr/X11/lib -lmlx -lXext -lX11

LIB = -L./libft -lft

SRC = main.c minilib.c ft_gettab.c key_hook.c ft_draw_line_in_image.c \
	ft_proj_iso.c ft_regu_tab.c ft_zoom_tab.c make.c \
	ft_put_pixel_in_image.c ft_east.c ft_north.c ft_south.c ft_west.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -I libft/includes/ -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIB) $(LX11)
	@echo "                       \033[1;30m              @EEEEEEEEEEEEESSEQ.        \033[0m"
	@echo "                       \033[1;30m             JEEEEEEEEEEEEEEEEEE[        \033[0m"
	@echo "                       \033[1;30m             {EEEEEEEEEEEEEEEEEE1        \033[0m"
	@echo "                       \033[1;30m             @EEEEEEEEEEEEEEEEEEQ.       \033[0m"
	@echo "                       \033[1;30m        *G@EEEEEEEEEEEEEEEEEEEEEEEEEEP*  \033[0m"
	@echo "                       \033[1;37m             J1:::z:=c.;.=::z::JL        \033[0m"
	@echo "                       \033[1;30m            E3@sSSSSS@sz@SSSSSb@Ed.      \033[0m"
	@echo "                       \033[1;30m            3E$EEEEEEEF3EEEEEEEEZQE[     \033[0m"
	@echo "                       \033[1;30m             V$?5GGGGGRF\033[1;37m::\033[1;30m?5GGGGP5$Q.:   \033[0m"
	@echo "                       \033[1;37m             '$c....:.z:::::....:.:$F    \033[0m"
	@echo "                       \033[1;37m               E)::;;Z2H5L;.;:3.         \033[0m"
	@echo "                       \033[1;37m                1J3\033[1;30mE5E5EE51t\033[1;37m[!F          \033[0m"
	@echo "                       \033[1;37m                 \033[1;37m[\033[1;30mL:\033[1;37m::::::\033[1;30m::y\033[1;37mF           \033[0m"
	@echo "                       \033[1;37m                  \033[1;30m*c\033[1;37m::\033[1;30m::\033[1;37m::\033[1;30m;*             \033[0m"
	@echo "                       \033[1;30m                    ^****^                \033[0m"
	@echo "                                                                                         "
	@echo "\033[34m"
	@echo " ____________   ___________   _____________   __________   _____________   _____________"
	@echo "|          2 | |        53 | |          34 | |        7 | |           4 | |         111 |"
	@echo "| H  H       | | IIIII     | |  SSS        | | N   N    | | BBBB        | | RRRR        |"
	@echo "| H  H       | |   I       | | S           | | NN  N    | | B   B       | | R   R   ggg |"
	@echo "| HHHH  eee  | |   I       | |  SSS   eee  | | N N N    | | BBBB   eee  | | RRRR   g  g |"
	@echo "| H  H e e   | |   I       | |     S e e   | | N  NN    | | B   B e e   | | R   R   ggg |"
	@echo "| H  H  eeee | | IIIII     | |  SSS   eeee | | N   N    | | BBBB   eeee | | R   R gggg  |"
	@echo "|____________| |___________| |_____________| |__________| |_____________| |_____________|"
	@echo "\033[32m"
	@echo "         ____________                                      _____________       "
	@echo "        |         35 |                                    |          56 |      "
	@echo "        | BBBB       |              k    i                | BBBB        |    d "
	@echo "        | B   B      |              k                     | B   B       |    d "
	@echo "        | BBBB  R RR |  eee   aaaa  k k  i  nnn    ggg    | BBBB   aaaa |  ddd "
	@echo "        | B   B Rr   | e e   a   a  kk   i  n  n  g  g    | B   B a   a | d  d "
	@echo "        | BBBB  R    |  eeee  aa a  k k  i  n  n   ggg    | BBBB   aa a |  ddd "
	@echo "        |____________|                           gggg     |_____________|      "
	@echo "                                                                               "










clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f *~

re: fclean all
