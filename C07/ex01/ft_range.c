/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:48:29 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/20 12:06:08 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	long long	length;
	int			*range;
	long long	idx;
	int			input_num;

	if (min >= max)
		return (0);
	length = max - min;
	range = (int *)malloc(length * sizeof(int));
	idx = 0;
	input_num = min;
	while (idx < length)
	{
		range[idx] = input_num;
		input_num++;
		idx++;
	}
	return (range);
}
