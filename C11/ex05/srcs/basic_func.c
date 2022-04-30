/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:40:01 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:40:03 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft.h"

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
