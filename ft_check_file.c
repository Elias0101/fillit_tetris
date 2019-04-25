/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:50:13 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/25 12:03:18 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_valid(char *term)
{
	int block;
	int i;
	int count;

	count = 0;
	block = 0;
	i = 0;
	while (i < 20)
	{
		if (term[i] == '#')
		{
			if ((i + 1) < 20 && term[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && term[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && term[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && term[i - 5] == '#')
				block++;
			count++;
		}
		i++;
	}
	return ((block == 6 || block == 8) && (count == 4));
}

static int	ft_check_term(char *line, int ref)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 != 4)
		{
			if (line[i] != '.' && line[i] != '#')
				return (-1);
		}
		else
		{
			if (line[i] != '\n')
				return (-2);
		}
		i++;
	}
	if (ref == 21 && line[20] != '\n')
		return (-3);
	if (!(ft_check_valid(line)))
		return (-4);
	return (0);
}

int			ft_check_file(int fd)
{
	int		ref;
	char	*line;
	int		count_term;

	if (!(line = ft_strnew(21))) // Зафришить память
		return (-2);
	count_term = 0;
	while ((ref = read(fd, line, 21)) == 21)
	{
		if (ft_check_term(line, ref) != 0)
			return (-1);
		count_term++;
	}
	if (ref != 20)
		return (-1);
	if ((ft_check_term(line, ref) != 0))
		return (-1);
	if (count_term > 26)
		return (-1);
	return (0);
}
