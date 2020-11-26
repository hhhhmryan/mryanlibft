/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryan <mryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:46:38 by mryan             #+#    #+#             */
/*   Updated: 2020/11/09 14:08:56 by mryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_rang(unsigned int n)
{
	int count;

	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char		*ft_zero(char *str, int n)
{
	if (n == 0)
	{
		str[0] = 0 + 48;
		str[1] = '\0';
	}
	return (str);
}

static char		*ft_fillin(char *str, unsigned int num, int rang)
{
	int i;

	i = 0;
	while (num > 0)
	{
		str[rang - i - 1] = (num % 10) + 48;
		num = num / 10;
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int				rang;
	char			*str;
	int				i;
	unsigned int	num;

	i = 0;
	rang = 0;
	if (n < 0)
	{
		rang += 1;
		num = -n;
	}
	else
		num = n;
	rang = rang + ft_rang(num);
	str = (char *)malloc((rang + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (rang > ft_rang(num))
		str[0] = '-';
	ft_zero(str, n);
	ft_fillin(str, num, rang);
	str[rang] = '\0';
	return (str);
}
