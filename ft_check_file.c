/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:50:13 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/22 14:26:20 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_check_line(char *line)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (line[i] != '.' && line[i] != '#')
			return (NULL);
		i++;
	}
	return (ft_strdup(line));
}

static char	ft_defin_term(char **term)
{
	size_t i;
	size_t j;
	// Проверка на фигуры и определение их
	term = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			//if (term[i][j] == '#' && !(term[i + 1][j] == '#' || term[i][j + 1]
			//== '#' || term[i - 1][j] == '#' || term[i][j - 1] == '#'))
			//	return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_check_file(int fd)
{
	char	*line;
	size_t	num_str;
	size_t	num_term;
	size_t	num_str_term;
	char	*term[4];
	char	terms[26];

	num_str = 0;
	while (get_next_line(fd, &line) && (num_term = num_str / 5) < 26)
	{
		num_str_term = num_str % 5;
		ft_putnbr(num_str);
		ft_putnbr(num_str_term);
		ft_putendl(line);
		//ft_putendl("s");
		if (num_str_term == 4)
		{
			if ((*line) != '\0')// Проверка на пустую 5 строку
				return (-1);
			if ((terms[num_term] = ft_defin_term(term)) == 0)
				return (-2);
		}
		else
		{
			if (ft_strlen(line) != 4)
				return (-3);
			if ((term[num_str_term] = ft_check_line(line)) == NULL)
				return (-4);
		}
		free(line);
		line = NULL;
		num_str++;
	}
	//if (get_next_line(fd, &line) != 0 || num_term >= 26 || line != NULL)
	//	return (-5); //Проверка на последнюю строку
	return (0);
}
