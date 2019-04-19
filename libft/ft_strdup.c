/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:02:46 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/05 17:17:03 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*p;

	l = ft_strlen(s1);
	p = (char *)malloc(sizeof(*p) * (l + 1));
	if (!p)
		return (NULL);
	while (l > 0)
	{
		p[l] = s1[l];
		l--;
	}
	p[l] = s1[l];
	return (p);
}
