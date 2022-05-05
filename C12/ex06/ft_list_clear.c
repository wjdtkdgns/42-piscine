/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:40:14 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 15:40:15 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	tracking(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*list;

	list = begin_list;
	if (list == 0)
		return ;
	if (list->next)
		tracking (list->next, free_fct);
	free_fct (list->data);
	free (list->next);
	return ;
}

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	tracking (begin_list, free_fct);
	free (begin_list);
}
