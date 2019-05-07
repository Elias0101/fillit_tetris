# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 18:27:40 by smanhack          #+#    #+#              #
#    Updated: 2019/05/07 13:08:31 by smanhack         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= map.c ft_check_file.c recursion.c if_possible_to_fill_figure.c

FLAGS	= -Wall -Wextra -Werror

LIB = ./libft/

all: $(NAME)

$(NAME):
	@make -C $(LIB) re
	gcc $(FLAGS) -o $(NAME) $(SRC) -I. -L$(LIB) -lft

clean:
	@make -C $(LIB) clean

fclean: clean
	@make -C $(LIB) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re