/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:40:24 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:40:25 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		idx;
	t_list	*list;
	t_list	*first;

	if (size <= 0)
		return (0);
	idx = 1;
	list = ft_create_elem((void *)strs[size - 1]);
	first = list;
	while (idx < size)
	{
		list -> next = ft_create_elem((void *)strs[size - idx - 1]);
		list = list -> next;
		idx++;
	}
	return (first);
}
