/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:09:59 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/20 18:29:00 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	length;
	int			*num_range;
	long long	idx;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	length = max - min;
	num_range = (int *)malloc(length * 4);
	if (!num_range)
	{
		*range = 0;
		return (-1);
	}
	idx = 0;
	while (min + idx < max)
	{
		num_range[idx] = min + idx;
		idx++;
	}
	*range = num_range;
	return (length);
}
