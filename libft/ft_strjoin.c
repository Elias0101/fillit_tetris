/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:07:07 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/07 16:07:15 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	unsigned int	i;

	if (s1 && s2)
	{
		p = (char *)malloc(sizeof(*p) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (p)
		{
			i = 0;
			while (*s1 != '\0')
			{
				p[i++] = *s1;
				s1++;
			}
			while (*s2 != '\0')
			{
				p[i++] = *s2;
				s2++;
			}
			p[i] = '\0';
			return (p);
		}
	}
	return (NULL);
}
