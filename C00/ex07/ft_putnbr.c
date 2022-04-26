/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:56:01 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/14 11:57:23 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb)
{
	char	lastnum;

	if (nb < 0)
	{
		write (1, "-", 1);
		lastnum = -(nb % 10) + '0';
		if (-(nb / 10) > 0)
			ft_putnbr (-(nb / 10));
	}
	else if (nb / 10 > 0)
	{
		lastnum = nb % 10 + '0';
		ft_putnbr (nb / 10);
	}
	else
		lastnum = nb + '0';
	write (1, &lastnum, 1);
}
