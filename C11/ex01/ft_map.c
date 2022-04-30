/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:35:25 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:35:28 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*rtn;
	int	idx;

	rtn = (int *)malloc(sizeof(int) * length);
	idx = 0;
	while (idx < length)
	{
		rtn[idx] = f (tab[idx]);
		idx++;
	}
	return (rtn);
}
