/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryan <mryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:28:27 by mryan             #+#    #+#             */
/*   Updated: 2020/11/09 15:56:29 by mryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*q;

	i = 0;
	p = (unsigned char *)dst;
	q = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (NULL);
	if (dst <= src)
	{
		ft_memcpy(dst, src, n);
	}
	else if (dst > src)
	{
		while (n > 0)
		{
			p[n - 1] = q[n - 1];
			n--;
		}
	}
	return (dst);
}
