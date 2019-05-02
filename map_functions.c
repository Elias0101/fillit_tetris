/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:39:06 by tkarri            #+#    #+#             */
/*   Updated: 2019/05/02 19:17:29 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_answer(char **map, int size)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < size)
	{
		while (++j < size)
		{
			ft_putchar(map[i][j]);
			if (j + 1 != size)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		j = -1;
	}
}
