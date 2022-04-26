/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:54:35 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/14 11:24:13 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_num(int num)
{
	int	ten;
	int	one;

	ten = num / 10 + '0';
	one = num % 10 + '0';
	ft_putchar (ten);
	ft_putchar (one);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			ft_num (num1);
			write (1, " ", 1);
			ft_num (num2);
			if (num1 + num2 != 197)
				write (1, ", ", 2);
			num2++;
		}
		num1++;
	}
}
