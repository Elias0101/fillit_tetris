/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:42:52 by smanhack          #+#    #+#             */
/*   Updated: 2019/05/06 18:06:36 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_answer(int map_size, char **map)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < map_size)
	{
		while (++j < map_size)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
		j = -1;
	}
}

void	ft_map_free(char ***map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

char	**ft_map_create(int size)
{
	char	**map;
	int		i;

	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * size)))
		{
			while (i--)
				free(map[i]);
			free(map);
			return (NULL);
		}
		ft_memset(map[i], EMPTY, size);
		i++;
	}
	return (map);
}

char	**ft_map_updata(char ***map, int size)
{
	ft_map_free(map, size);
	return (ft_map_create(size + 1));
}

int		ft_min_sqrt(int count)
{
	int i;

	i = 1;
	while ((i * i) < count)
		i++;
	return (i);
}
