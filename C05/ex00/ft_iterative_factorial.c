/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:36:01 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 16:37:08 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	idx;
	int	ans;

	ans = 1;
	idx = 1;
	if (nb < 0)
		return (0);
	while (idx <= nb)
	{
		ans *= idx;
		idx++;
	}
	return (ans);
}
