/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryan <mryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:51:26 by mryan             #+#    #+#             */
/*   Updated: 2020/11/04 17:16:42 by mryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	void			*res;

	i = 0;
	p = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			res = &p[i];
			return ((void *)res);
		}
		i++;
	}
	return (0);
}
