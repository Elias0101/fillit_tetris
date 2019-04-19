/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:07:42 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/19 16:04:25 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5

# include <libc.h>
# include "libft.h"

typedef struct		s_file
{
	int				fd;
	char			*line;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
