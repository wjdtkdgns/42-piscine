/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:28:25 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 14:28:27 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*cur_list;

	cur_list = begin_list;
	while (cur_list -> next != 0)
	{
		cur_list = cur_list -> next;
	}
	return (cur_list);
}
