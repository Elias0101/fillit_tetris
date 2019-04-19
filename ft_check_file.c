/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:50:13 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/19 15:51:41 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_file(int fd)
{
	char *line;
	size_t num_str;
	size_t num_term;
	size_t num_str_term;

	line = NULL;
	num_str = 0;
	while (get_next_line(fd, &line))
	{
		num_str_term = num_str % 4;
		num_term = num_str / 4;
		if (num_str_term == 3)
		{
			if (*line != '\0')
				return (-1);
		}
		else
		{
			if ((ft_strlen(line) != 4) && (ft_strchr()))
		}
		// Проверка на символы и фигуры!!!!
		free(line);
		num_str++;
	}
	if (get_next_line(fd, &line) != 0) //|| (num_str / 4) > 25)
		return (-1);
}