# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tuperera <tuperera@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/04 15:35:51 by tuperera       #+#    #+#                 #
#    Updated: 2020/02/08 10:35:19 by tuperera      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = libft/libft.a

GNL = gnl/gnl.a

MINILIBX = libmlx.dylib

FLAGS = -Wall -Werror -Wextra

INCLUDES = include/

SRC = calc_text.c calculate.c check_functions.c check_functions2.c color.c \
		init.c map.c move.c render.c main.c sprite.c file_functions.c \
		render_ex.c map_ex.c bmp_save.c error_check.c

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re all bonus library

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(GNL) $(OBJ)
	gcc -o $(NAME) $(MINILIBX) $(LIBFT) $(GNL) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES) -c $<

$(GNL):
	$(MAKE) -C gnl all

$(LIBFT):
	$(MAKE) -C libft all bonus

$(MINILIBX):
	$(MAKE) -C minilibx all
	mv minilibx/libmlx.dylib ./

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C gnl clean
	$(MAKE) -C minilibx clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(MINILIBX)
	$(MAKE) -C libft fclean
	$(MAKE) -C gnl fclean

re: fclean all
