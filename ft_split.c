/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryan <mryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:18:58 by mryan             #+#    #+#             */
/*   Updated: 2020/11/13 20:40:38 by mryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] == c)
		{
			count++;
		}
		else if (s[i] != c && s[i + 1] == '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_sublen(char const *s, char c, size_t j)
{
	size_t cw;

	cw = 0;
	while (s[j] != c && s[j] != 0)
	{
		cw++;
		j++;
	}
	return (cw);
}

static char		**ft_free(char **arr, int i)
{
	while (i > -1)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	count = ft_wordcount(s, c);
	if (!(arr = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	while (i < count)
	{
		while (s[j] == c)
			j++;
		arr[i] = ft_substr(s, j, ft_sublen(s, c, j));
		if (arr[i] == NULL)
			return (ft_free(arr, i));
		j = j + ft_sublen(s, c, j);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
