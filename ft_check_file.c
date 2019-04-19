/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:50:13 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/19 17:11:35 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_check_line(char *line)
{
	char	i;

	i = 0;
	while (i < 4)
	{
		if (line[i] != '.' && line[i] != '#')
			return (NULL);
		i++;
	}
	return (ft_strdup(*line));
}

char	ft_defin_term()
{
	return (1);
}

int		ft_check_file(int fd, char **terms)
{
	char	*line;
	size_t	num_str;
	size_t	num_term;
	size_t	num_str_term;
	char	*term[4];

	line = NULL;
	num_str = 0;
	while (get_next_line(fd, &line) && (num_term = num_str / 4) < 26)
	{
		num_str_term = num_str % 4;
		if (num_str_term == 3)
		{
			if (*line != '\0')
				return (-1);
			if ((terms[num_term] = ft_defin_term()) == 0)
				return (-1);
		}
		else
		{
			if (ft_strlen(line) != 4)
				return (-1);
			if ((term[num_str_term] = ft_check_line(line)) == NULL)
				return (-1);
		}
		free(line);
		num_str++;
	}
	if (get_next_line(fd, &line) != 0 || num_term == 26)
		return (-1);
}