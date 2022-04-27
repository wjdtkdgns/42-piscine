/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:55:01 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/17 17:07:43 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	hexa(char num)
{
	if (num >= 10)
		return (num - 10 + 'a');
	else
		return (num + '0');
}

void	convert_16(int str)
{
	char	ten;
	char	one;
	char	hexa_num;

	ten = str / 16;
	one = str % 16;
	write (1, "\\", 1);
	hexa_num = hexa(ten);
	write (1, &hexa_num, 1);
	hexa_num = hexa(one);
	write (1, &hexa_num, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				idx;
	unsigned char	a;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < 32 || str[idx] == 127)
		{
			a = str[idx];
			convert_16(a);
		}
		else
			write(1, &(str[idx]), 1);
		idx++;
	}
}
