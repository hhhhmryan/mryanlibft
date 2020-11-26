/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryan <mryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:18:30 by mryan             #+#    #+#             */
/*   Updated: 2020/11/09 15:57:23 by mryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t needlen;

	i = 0;
	j = 0;
	needlen = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && i < len)
	{
		if (len - i < needlen)
			return (NULL);
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, needlen) == 0)
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
