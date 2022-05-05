/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:39:58 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:40:00 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	idx;
	t_list			*list;

	idx = 0;
	list = begin_list;
	while (idx < nbr)
	{
		if (list->next)
			list = list->next;
		else
			return (0);
		idx++;
	}
	return (list);
}
