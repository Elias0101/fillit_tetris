# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 18:27:40 by smanhack          #+#    #+#              #
#    Updated: 2019/05/02 18:23:54 by tkarri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

HDR = includes/

OBJ = $(SRC:%.c=%.o);

$(NAME) :
	gcc $(FLAGS) -I. -L./libft -lft recursion.c if_possible_to_fill_figure.c ft_check_file.c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
