#include <stdio.h>
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define EMPTY_T '~'

char **g_map;

int g_map_size;

int g_count_f;

void    print_answer(void)
{
  int i;
  int j;

  i = -1;
  j = -1;
  while (++i < g_map_size)
    {
      while (++j < g_map_size)
        printf("%c ", g_map[i][j]);
      printf("\n");
      j = -1;
    }
}

void	change_combination(t_term *figure, int *id_current, int *i, int *j)
{
	int i_last;
	int j_last;
	int tmp;
	t_term *last_felt;

	if (*id_current == 0) //не хватает размера
	{
		*i = 0;
		*j = -1;
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
		*j = j_last; //начинаем со следующего базового квадрата
		*id_current -= 1;
	}
	//print_answer();
}

void	fill_figure(t_term *figure, int id_current)
{
	int i;
	t_term *curr;

	curr = figure + id_current;
	i = -1;
	while (++i < 4)
		g_map[(curr->y)[i]][(curr->x)[i]] = 'A' + id_current;
	//print_answer();
}

void	fill_it(t_term *figure)
{
	static int id_current;
	static int i;
	static int j;

	//printf("iteration: i = %d; j = %d; id_current = %d; g_map_size = %d\n", i, j, id_current, g_map_size);
	if (id_current == g_count_f)
		return ;
	if (j == g_map_size)
	{
		j = 0;
		i++;
	}
	if (i == g_map_size)
	{
		change_combination(figure, &id_current, &i, &j);
	}
	else if (g_map[i][j] == EMPTY_T && if_possible(g_map, g_map_size, figure + id_current, i, j))
	{
		fill_figure(figure, id_current);
		id_current++;
		i = 0;
		j = -1;
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
		ft_memset(g_map[i], '~', 24);
		i++;
	}
	//printf("\n\n\nReading was done\n\n");
	g_map_size = 1;
	//print_figure(data);
	//print_answer();
	fill_it(data);
	print_answer();
	//printf("\n\nAFTER ANSWER:\ng_map_size: %d\ng_count_f: %d\n", g_map_size, g_count_f);
	free(line);
	close(fd);
	return (0);
}
