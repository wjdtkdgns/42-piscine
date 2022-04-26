/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:38:44 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 16:40:00 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	idx;
	int	num;

	idx = 0;
	num = nb;
	if (power > 0)
	{
		while (idx < power - 1)
		{
			nb *= num;
			idx++;
		}
	}
	else if (power == 0)
		return (1);
	else
		return (0);
	return (nb);
}
