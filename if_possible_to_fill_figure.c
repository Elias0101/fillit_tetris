#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"
#define EMPTY '0'

int	is_empty_and_correct(t_term *figure, int size, char **map)
{
  int i;

  i = -1;
  while (++i < 4)
    {
      if ((figure->x)[i] >= size || (figure->y)[i] >= size || (figure->x)[i] < 0 || (figure->y)[i] < 0 ||
	  map[(figure->y)[i]][(figure->x)[i]] != EMPTY)
	return (0);
    }
  return (1);
}

int	if_possible(char **map, int size, t_term *figure, int i, int j)
{
  int change_i;
  int change_j;
  int diff_i;
  int diff_j;

  diff_i = i - (figure->y)[0];
  diff_j = j - (figure->x)[0];
  change_i = 0;
  change_j = -1;
  while (++change_i <= 2)
    {
      while (++change_j < 4)
	{
	  if (change_i == 1)
	      (figure->x)[change_j] += diff_j;
	  else
	      (figure->y)[change_j] += diff_i;
	}
      change_j = -1;
    }
  return (is_empty_and_correct(figure, size, map));
}
/*
int main(int ac, char **av)
{
  t_term *figure = (t_term *)malloc(sizeof(t_term));
  figure->x[0] = 0;
  figure->y[0] = 0;
  figure->x[1] = 1;
  figure->y[1] = 0;
  figure->x[2] = 0;
  figure->y[2] = 1;
  figure->x[3] = 1;
  figure->y[3] = 1;
  if (ac > 1)
    {
      printf("%c\n", av[1][0]);
      printf("%d\n", if_possible(av, 4, figure, 2, 3));
    }
  free(figure);
  return (0);
}
*/
