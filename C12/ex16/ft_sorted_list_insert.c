/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:27:05 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:27:07 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort_increase_ex16(t_list **begin_list, int (*cmp)())
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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;

	new = ft_create_elem (data);
	new->next = *begin_list;
	ft_list_sort_increase_ex16 (&new, cmp);
	*begin_list = new;
}
