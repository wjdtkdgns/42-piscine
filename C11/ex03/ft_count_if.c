/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:36:35 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:36:37 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	rtn;
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (idx < length)
	{
		rtn = f(tab[idx]);
		if (rtn != 0)
			count++;
		idx++;
	}
	return (count);
}
