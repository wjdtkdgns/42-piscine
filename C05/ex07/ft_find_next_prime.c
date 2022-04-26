/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:44:36 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 16:45:06 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	is_prime(unsigned int num)
{
	unsigned int	idx;

	if (num < 2)
		return (0);
	if (num == 2 || num == 3)
		return (1);
	else if (num == 5 || num == 7)
		return (1);
	if (num % 2 == 0 || num % 3 == 0)
		return (0);
	else if (num % 5 == 0 || num % 7 == 0)
		return (0);
	idx = 2;
	while (idx * idx <= num)
	{
		if (num % idx == 0)
			return (0);
		idx += 1;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	unsigned int	num;

	if (nb <= 2)
		return (2);
	num = nb;
	while (!is_prime(num))
		num++;
	return (num);
}
