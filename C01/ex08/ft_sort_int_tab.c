/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:24:54 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/14 18:29:38 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	num1;
	int	num2;
	int	keep;

	num1 = 0;
	while (num1 < size - 1)
	{
		num2 = num1 + 1;
		while (num2 < size)
		{
			if (tab[num1] > tab[num2])
			{
				keep = tab[num1];
				tab[num1] = tab[num2];
				tab[num2] = keep;
			}
			num2++;
		}
		num1++;
	}
}
