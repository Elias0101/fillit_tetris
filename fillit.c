/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:50:12 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/30 12:29:55 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

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
	} // Зафришить память
	if (fd < 0 || ft_check_file(fd, line, data) != 0)
	{
		free(line);
		free(data);
		ft_putendl("error");
		return (0);
	}
	free(line);
	
	close(fd);
	return (0);
}
