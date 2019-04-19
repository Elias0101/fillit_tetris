/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:57:23 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/07 18:57:24 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *p;

	if (s)
	{
		p = ft_strnew(len);
		if (p)
		{
			while (len--)
				p[len] = s[start + len];
			return (p);
		}
	}
	return (NULL);
}
