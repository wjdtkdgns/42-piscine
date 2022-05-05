/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:38:40 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:38:42 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_make_reverse(t_list **reverse, t_list *list)
{
	if (*reverse)
	{
		list->next = (*reverse);
		(*reverse) = list;
	}
	else
		(*reverse) = list;
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*reverse;
	t_list	*list;
	t_list	*next;

	reverse = 0;
	list = *begin_list;
	while (list)
	{
		next = list->next;
		ft_make_reverse(&reverse, list);
		list = next;
	}
	(*begin_list)->next = 0;
	*begin_list = reverse;
}
