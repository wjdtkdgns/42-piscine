/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:31:01 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:31:04 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	void	*keep;

	list = *begin_list;
	while (list && list->next)
	{
		if (cmp (list->data, list->next->data) > 0)
		{
			keep = list->data;
			list->data = list->next->data;
			list->next->data = keep;
			list = *begin_list;
			continue ;
		}
		list = list->next;
	}
}
