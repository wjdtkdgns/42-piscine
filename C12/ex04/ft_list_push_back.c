/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:28:39 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 14:28:45 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*cur_list;

	cur_list = *begin_list;
	if (cur_list)
	{
		while (cur_list->next)
			cur_list = cur_list->next;
		cur_list->next = ft_create_elem(data);
	}
	else
		cur_list = ft_create_elem(data);
}
