/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:40 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:32:42 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list
, void *data_ref, int (*cmp)(), void (*free_cnt)(void *))
{
	t_list	*cur;
	t_list	*rm;

	cur = *begin_list;
	while (cur && cur->next)
	{
		if (!cmp (cur->next->data, data_ref))
		{
			rm = cur->next;
			cur->next = cur->next->next;
			free_cnt (rm->data);
			free (rm);
		}
		cur = cur->next;
	}
	cur = *begin_list;
	if (cur && !cmp (cur->data, data_ref))
	{
		rm = cur;
		cur = cur->next;
		free_cnt (rm->data);
		free (rm);
		*begin_list = cur;
	}
}
