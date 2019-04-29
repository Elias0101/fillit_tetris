#include <stdio.h>
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#define EMPTY_T '0'

char **g_map;

int g_map_size;

int g_count_f;

void	change_combination(t_term *figure, int *id_current, int *i, int *j)
{
	int i_last;
	int j_last;
	int tmp;
	t_term *last_felt;

	if (*id_current == 0) //не хватает размера
	{
		*i = 0;
		*j = 0;
		g_map_size++;
	}
	else //меняем комбинацию б.к.
	{
		tmp = -1;
		last_felt = figure + *id_current - 1;
		j_last = (last_felt->x)[0];
		i_last = (last_felt->y)[0];
		while (++tmp < 4)
			g_map[(last_felt->y)[tmp]][(last_felt->x)[tmp]] = EMPTY_T;
		*i = i_last;
		*j = j_last + 1; //начинаем со следующего базового квадрата
	}
}

void	fill_figure(t_term *figure, int id_current)
{
	int i;
	t_term *curr;

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

	if (id_current == g_count_f) //вписали все элементы ? хорош
		return ;
	if (j == g_map_size) //следующее id
	{
		j = 0;
		i++;
	}
	if (i == g_map_size) //не вписали все элементы и дошли до конца
	{
		change_combination(figure, &id_current, &i, &j);
		fill_it(figure);
	}
	if (g_map[i][j] == EMPTY_T && if_possible(g_map, g_map_size, figure + id_current, i, j))
	{
		fill_figure(figure, id_current);
		id_current++;
	}
	else if (++j > 0)
		fill_it(figure);
}
