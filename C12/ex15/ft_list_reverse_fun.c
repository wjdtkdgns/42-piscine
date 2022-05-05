/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:29:14 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:29:16 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list *first, t_list *last)
{
	void	*keep;

	keep = first->data;
	first->data = last->data;
	last->data = keep;
}

t_list	*ft_take_list(int idx, t_list *list)
{
	int		i;
	t_list	*rtn;

	i = 0;
	rtn = list;
	while (i < idx)
	{
		rtn = rtn->next;
		i++;
	}
	return (rtn);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*list;
	int		len;
	int		idx;

	list = begin_list;
	len = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		len++;
	}
	idx = 0;
	while (idx < len / 2)
	{
		ft_swap(ft_take_list (idx, list), ft_take_list (len - idx - 1, list));
		idx++;
	}
}
