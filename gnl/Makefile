# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tuperera <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 13:06:02 by tuperera       #+#    #+#                 #
#    Updated: 2020/02/08 10:35:31 by tuperera      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

FLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re all bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c
	gcc $(FLAGS) -c $<

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
