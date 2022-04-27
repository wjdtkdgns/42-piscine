/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:19:50 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/16 16:47:26 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	num;
	int	keep;

	num = 0;
	while (size / 2 > num)
	{
		keep = tab[num];
		tab[num] = tab[size - num -1];
		tab[size - num -1] = keep;
		num++;
	}
}
