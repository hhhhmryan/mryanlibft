/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryan <mryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:12:59 by mryan             #+#    #+#             */
/*   Updated: 2020/11/10 16:48:58 by mryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t i;
	size_t start;

	i = 0;
	start = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
		{
			start = i;
			break ;
		}
		i++;
	}
	return (start);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t i;
	size_t end;

	i = 0;
	end = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
		{
			end = i;
		}
		i++;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t lenstr;
	size_t start;
	size_t end;

	i = 0;
	lenstr = 0;
	start = 0;
	end = 0;
	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup((char *)s1));
	i = ft_start(s1, set);
	start = i;
	end = ft_end(s1, set);
	if (end != 0)
		lenstr = end - start + 1;
	else
		lenstr = 0;
	return (ft_substr(s1, start, lenstr));
}
