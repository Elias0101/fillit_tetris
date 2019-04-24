/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:50:13 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/24 17:21:17 by smanhack         ###   ########.fr       */
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
			if (line[i] != '\n')
				return (-2);
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

	if (!(line = ft_strnew(21)))
		return (-2);
	count_term = 0;
	while ((ref = read(fd, line, 21)) >= 20)
	{
		ft_putnbr(count_term);
		ft_putchar('\n');
		ft_putstr(line);
		if (ft_check_term(line, ref) != 0)
			return (-1);
		count_term++;
	}
	if (count_term > 26)
		return (-1);
	/*
	char	*line;
	size_t	num_str;
	size_t	num_term;
	size_t	num_str_term;
	char	*term;
	//char	terms[26];

	num_str = 0;
	term = ft_memalloc(16);
	while (get_next_line(fd, &line) && (num_term = num_str / 5) < 26)
	{
		num_str_term = num_str % 5;
		ft_putnbr(num_str);
		ft_putnbr(num_str_term);
		ft_putendl(line);
		//ft_putendl("s");
		if (num_str_term == 4)
		{
			if ((*line) != '\0')
				return (-1);
			//if (ft_defin_term(term))
			//	return (-2);
			free (term);
		}
		else
		{
			if (ft_strlen(line) != 4)
				return (-3);
			if (ft_check_line(line) == NULL)
				return (-4);
			//term = ft_memcpy((void *)term + (4 * num_term), line, 4);
		}
		//free(line);
		//line = NULL;
		num_str++;
	}
	//ft_putnbr(num_str);
	//ft_putnbr(num_str_term);
	ft_putstr(line);
	if (num_term == 26 || num_str_term != 3)
		return (-5);
	*/
	//ft_putchar('\n');
	return (0);
}
