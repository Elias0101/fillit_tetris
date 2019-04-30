/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:55:39 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/30 13:52:40 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include <libc.h>

typedef	struct	s_term
{
	int			x[4];
	int			y[4];

}				t_term;

int		ft_check_file(int fd, char *line, t_term *data);

int		is_empty_and_correct(t_term *figure, int size, char **map);

int		if_possible(char **map, int size, t_term *figure, int i, int j);

#endif
