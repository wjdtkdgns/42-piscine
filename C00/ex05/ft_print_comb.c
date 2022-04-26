/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:46:21 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/13 17:39:36 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_comb(void)
{
	char	num1;
	char	num2;
	char	num3;

	num1 = '0';
	while (num1 <= '6')
	{
		num2 = num1 + 1;
		while (num2 <= '8')
		{
			num3 = num2 + 1;
			while (num3 <= '9')
			{
				write(1, &num1, 1);
				write(1, &num2, 1);
				write(1, &num3, 1);
				write(1, ", ", 2);
				num3++;
			}
			num2++;
		}
		num1++;
		if (num1 == '7')
			write(1, "789", 3);
	}
}
