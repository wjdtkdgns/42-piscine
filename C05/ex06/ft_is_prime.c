/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:43:34 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 16:44:00 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_is_prime(int nb)
{
	int	idx;

	if (nb <= 1)
		return (0);
	idx = 2;
	while (idx < nb)
	{
		if (nb % idx == 0)
			return (0);
		idx++;
	}
	return (1);
}
