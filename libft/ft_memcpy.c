/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:06:33 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/14 18:31:50 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	s = (unsigned char *)src + (n - 1);
	d = (unsigned char *)dst + (n - 1);
	while (n > 0)
	{
		*d = *s;
		d--;
		s--;
		n--;
	}
	return (dst);
}
