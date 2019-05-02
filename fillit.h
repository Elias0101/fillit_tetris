/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:55:39 by smanhack          #+#    #+#             */
/*   Updated: 2019/05/02 19:19:18 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define EMPTY '.'
# include "libft/includes/libft.h"
# include <libc.h>
# include <stdio.h> //delete - make write's
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_term
{
	int			x[4];
	int			y[4];

}				t_term;

int				ft_check_file(int fd, char *line, t_term *data);

int				try_record(t_term *figure, int size, char **map);

int				move_figure(t_term *figure, int i, int j);

void			print_answer(char **map, int size);

#endif
