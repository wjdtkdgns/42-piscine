/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:20:40 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/24 13:12:38 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
	write (1, "\n", 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	char	*string;
	int		size;
	int		idx;

	idx = 0;
	while (par[idx].str)
	{
		string = par[idx].str;
		ft_putstr(string);
		size = par[idx].size;
		ft_putnbr(size);
		write(1, "\n", 1);
		string = par[idx].copy;
		ft_putstr(string);
		idx++;
	}
}
