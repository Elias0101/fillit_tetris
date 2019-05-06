/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:54:34 by tkarri            #+#    #+#             */
/*   Updated: 2019/05/06 18:34:57 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	**g_map;

int		g_map_size;

int		g_count_f;

void	change_combination(t_term *figure, int *id_current,
					int *i, int *j)
{
	int		i_last;
	int		j_last;
	int		tmp;
	t_term	*last_felt;

	if (*id_current == 0)
	{
		*i = 0;
		*j = -1;
		g_map = ft_map_updata(&g_map, g_map_size);
		g_map_size++;
	}
	else
	{
		tmp = -1;
		last_felt = figure + *id_current - 1;
		j_last = (last_felt->x)[0];
		i_last = (last_felt->y)[0];
		while (++tmp < 4)
			g_map[(last_felt->y)[tmp]][(last_felt->x)[tmp]] = EMPTY;
		*i = i_last;
		*j = j_last;
		*id_current -= 1;
	}
}

void	fill_figure(t_term *figure, int id_current)
{
	int		i;
	t_term	*curr;

	curr = figure + id_current;
	i = -1;
	while (++i < 4)
		g_map[(curr->y)[i]][(curr->x)[i]] = 'A' + id_current;
}

void	fill_it(t_term *figure)
{
	int id_current;
	int i;
	int j;

	id_current = 0;
	i = 0;
	j = 0;
	while (id_current != g_count_f)
	{
		if (j == g_map_size)
		{
			j = 0;
			i++;
		}
		if (i == g_map_size)
			change_combination(figure, &id_current, &i, &j);
		else if (g_map[i][j] == EMPTY && move_figure(figure + id_current, i, j)
		&& is_fillable(figure + id_current, g_map_size, g_map))
		{
			fill_figure(figure, id_current);
			id_current++;
			i = 0;
			j = -1;
		}
		j++;
	}
}

int		check_errors(t_term **data, int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(*data = (t_term *)malloc(sizeof(t_term) * 26)) ||
		!(line = ft_strnew(21)))
	{
		ft_putendl("error");
		return (0);
	}
	if (fd < 0 || (g_count_f = ft_check_file(fd, line, *data)) < 0)
	{
		free(line);
		free(*data);
		ft_putendl("error");
		return (0);
	}
	free(line);
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	t_term	*data;

	if (check_errors(&data, argc, argv) == 0)
		return (0);
	g_map_size = ft_min_sqrt(g_count_f * 4);
	g_map = ft_map_create(g_map_size);
	fill_it(data);
	free(data);
	if (g_map == NULL)
		ft_putendl("error");
	else
		print_answer(g_map_size, g_map);
	return (0);
}
