/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryan <mryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:09:06 by mryan             #+#    #+#             */
/*   Updated: 2020/11/13 12:39:22 by mryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list;

	list = (*lst);
	while (list)
	{
		list = list->next;
		ft_lstdelone(*lst, (*del));
		(*lst) = list;
	}
	lst = NULL;
}
