/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:15:27 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:18:46 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge_ex17(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	if (begin_list1 == 0)
		begin_list1 = &begin_list2;
	cur = *begin_list1;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur -> next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}

void	ft_list_sort_ex17(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	void	*keep;

	list = *begin_list;
	while (list && list -> next)
	{
		if (cmp (list -> data, list -> next -> data) > 0)
		{
			keep = list -> data;
			list -> data = list -> next -> data;
			list -> next -> data = keep;
			list = *begin_list;
			continue ;
		}
		list = list -> next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1
, t_list *begin_list2, int (*cmp)())
{
	ft_list_merge_ex17 (begin_list1, begin_list2);
	ft_list_sort_ex17 (begin_list1, cmp);
}
