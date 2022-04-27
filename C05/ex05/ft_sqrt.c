/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:42:48 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 16:43:10 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_sqrt(int nb)
{
	int	idx;
	int	pow_idx;

	idx = 1;
	if (nb == 1)
		return (1);
	while (idx < nb)
	{
		pow_idx = idx * idx;
		if (pow_idx > nb)
			return (0);
		else if (pow_idx == nb)
			return (idx);
		idx++;
	}
	return (0);
}
