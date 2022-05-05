/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:32:13 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:32:15 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	if (begin_list1 == 0)
		begin_list1 = &begin_list2;
	cur = *begin_list1;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
