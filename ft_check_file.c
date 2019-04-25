/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:50:13 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/25 14:52:21 by smanhack         ###   ########.fr       */
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

t_term	ft_mv_data(t_term cord)
{
	int		offset_x;
	int		offset_y;
	int		i;

	offset_x = 0;
	while ((cord.x[0] - offset_x) >= 0 && (cord.x[1] - offset_x) >= 0 && (cord.x[2] - offset_x) >= 0 && (cord.x[3] - offset_x) >= 0)
		offset_x++;
	offset_y = 0;
	while ((cord.y[0] - offset_y) >= 0 && (cord.y[1] - offset_y) >= 0 && (cord.y[2] - offset_y) >= 0 && (cord.y[3] - offset_y) >= 0)
		offset_y++;
	i = 0;
	while (i < 4)
		cord.x[i++] -= (offset_x - 1);
	i = 0;
	while (i < 4)
		cord.y[i++] -= (offset_y - 1);
	i = 0;
	ft_putnbr(offset_x);
	ft_putchar('\n');
	ft_putnbr(offset_y);
	while (i < 4)
	{
		ft_putchar('\n');
		ft_putnbr(cord.x[i]);
		ft_putchar(' ');
		ft_putnbr(cord.y[i]);
		ft_putchar('\n');
		i++;
	}
	return (cord);
}

t_term	ft_fill_data(char *line)
{
	t_term	cord;
	int		i;
	int		j;
 
	i = 0;
	j = 0;
	while (i < 19 && j < 4)
	{
		ft_putchar(line[i]);
		cord.x[j] = i / 5;
		cord.y[j] = i % 5;
		if (line[i++] == '#')
			j++;
	}
	/*i = 0;
	while (i < 4)
	{
		ft_putchar('\n');
		ft_putnbr(cord.x[i]);
		ft_putchar(' ');
		ft_putnbr(cord.y[i]);
		ft_putchar('\n');
		i++;
	}*/
	cord = ft_mv_data(cord);
	return (cord);
}

int			ft_check_file(int fd, char	*line, t_term	*data)
{
	int		ref;
	int		count_term;

	count_term = 0;
	while ((ref = read(fd, line, 21)) == 21)// Защита на колличество терминошек
	{
		if (ft_check_term(line, ref) != 0)
			return (-1);
		data[count_term] = ft_fill_data(line);
		count_term++;
	}
	if (ref != 20)
		return (-1);
	if ((ft_check_term(line, ref) != 0))
		return (-1);
	if (count_term > 26)
		return (-1);
	data[count_term] = ft_fill_data(line);
	return (0);
}
