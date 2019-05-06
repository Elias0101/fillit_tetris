/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:54:34 by tkarri            #+#    #+#             */
/*   Updated: 2019/05/06 16:47:00 by smanhack         ###   ########.fr       */
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

void	print_answer(void)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < g_map_size)
	{
		while (++j < g_map_size)
			ft_putchar(g_map[i][j]);
		ft_putchar('\n');
		j = -1;
	}
}

void	change_combination(t_term *figure, int *id_current,
					int *i, int *j)
{
	int		i_last;
	int		j_last;
	int		tmp;
	t_term		*last_felt;

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
	int 	i;
	t_term	*curr;

	curr = figure + id_current;
	i = -1;
	while (++i < 4)
		g_map[(curr->y)[i]][(curr->x)[i]] = 'A' + id_current;
}

void	fill_it(t_term *figure)
{
	static int id_current;
	static int i;
	static int j;

	print_answer();
	ft_putendl("fill_it started");
	if (id_current == g_count_f)
		return ;
	if (j == g_map_size)
	{
		j = 0;
		i++;
	}
	ft_putendl("if-else started");
	if (i == g_map_size)
	{
		ft_putendl("change_combination started");
		change_combination(figure, &id_current, &i, &j);
		ft_putendl("change_combination edned");
	}
	else if (g_map[i][j] == EMPTY && move_figure(figure + id_current, i, j))
	{
		ft_putendl("is_fillable started extern");
		if ((is_fillable(figure + id_current, g_map_size, g_map)))
		{
			ft_putendl("fill_figure started");
			fill_figure(figure, id_current);
			id_current++;
			i = 0;
			j = -1;
			ft_putendl("fill_figure ended");
		}
		ft_putendl("is_fillable ended extern");
	}
	ft_putendl("if-else ended");
	++j;
	ft_putendl("fill_it ended");
	fill_it(figure);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_term	*data;
	char	*line;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(data = (t_term *)malloc(sizeof(t_term) * 26)) ||
		!(line = ft_strnew(21)))
	{
		ft_putendl("error");
		return (0);
	}
	if (fd < 0 || (g_count_f = ft_check_file(fd, line, data)) < 0)
	{
		free(line);
		free(data);
		ft_putendl("error");
		return (0);
	}
	g_map_size = ft_min_sqrt(g_count_f * 4);
	g_map = ft_map_create(g_map_size);
	fill_it(data);
	print_answer();
	free(line);
	close(fd);
	return (0);
}
