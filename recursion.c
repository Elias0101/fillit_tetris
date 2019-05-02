/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:57:54 by tkarri            #+#    #+#             */
/*   Updated: 2019/05/02 19:33:24 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdlib.h>

#include <stdio.h>

#include <unistd.h>

char **g_map;

int g_map_size;

int g_count_f;

void	change_combination(t_term *figure, int *id_curr, int *i, int *j)
{
	int i_last;
	int j_last;
	int tmp;
	t_term *last_felt;

	if (*id_curr == 0) //не хватает размера
	{
		*i = 0;
		*j = -1;
		g_map_size++;
	}
	else //меняем комбинацию б.к.
	{
		tmp = -1;
		last_felt = figure + *id_curr - 1;
		j_last = (last_felt->x)[0];
		i_last = (last_felt->y)[0];
		while (++tmp < 4)
			g_map[(last_felt->y)[tmp]][(last_felt->x)[tmp]] = EMPTY;
		*i = i_last;
		*j = j_last; //начинаем со следующего базового квадрата
		*id_curr = (*id_curr) - 1;
	}
	//print_answer();
}

void	fill_figure(t_term *figure, int *id_curr, int *i, int *j)
{
	int f;
	t_term *curr;

	curr = figure + *id_curr;
	f = -1;
	while (++f < 4)
		g_map[(curr->y)[f]][(curr->x)[f]] = 'A' + *id_curr;
	*id_curr += 1;
	*i = 0;
	*j = -1;
}

void	fill_it(t_term *figure)
{
	static int id_curr;
	static int i;
	static int j;

	if (id_curr == g_count_f)
		return ;
	if (j == g_map_size)
	{
		j = 0;
		i++;
	}
	if (i == g_map_size)
	{
		change_combination(figure, &id_curr, &i, &j);
	}
	else if (g_map[i][j] == EMPTY && move_figure(figure + id_curr, i, j)
	&& try_record(figure + id_curr, g_map_size, g_map))
	{
		fill_figure(figure, &id_curr, &i, &j);
	}
	++j;
	fill_it(figure);
}

int     main(int argc, char **argv)
{
    int     fd;
    t_term  *data;
    char    *line;

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
	g_map = (char **)malloc(sizeof(char *) * 26);
	int i = 0;
	while (i < 26)
	{
		g_map[i] = (char *)malloc(sizeof(char) * 20);
		ft_memset(g_map[i], EMPTY, 24);
		i++;
	}
	//printf("\n\n\nReading was done\n\n");
	g_map_size = 1;
	//print_figure(data);
	//print_answer();
	printf("data filled\n");
	fill_it(data);
	printf("recursion ended\n");
	print_answer(g_map, g_map_size);
	//printf("\n\nAFTER ANSWER:\ng_map_size: %d\ng_count_f: %d\n", g_map_size, g_count_f);
	free(line);
	close(fd);
	return (0);
}
