/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:30:16 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 14:31:42 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	check_base(char *base)
{
	int	size;
	int	idx;

	size = 0;
	while (base[size])
	{
		idx = size + 1;
		while (base[idx])
		{
			if (base[idx] == base[size])
				return (0);
			idx++;
		}
		if (base[size] == '+' || base[size] == '-')
			return (0);
		size++;
	}
	if (size <= 1)
		return (0);
	return (size);
}

void	print_num(int cut_num, char *base)
{
	write(1, &(base[cut_num]), 1);
}

void	change_base(int base_num, int nbr, char *base)
{
	if (nbr < 0)
	{
		write (1, "-", 1);
		if (-(nbr / base_num) > 0)
			change_base (base_num, -(nbr / base_num), base);
		print_num (-(nbr % base_num), base);
	}
	else if (nbr / base_num > 0)
	{
		change_base (base_num, nbr / base_num, base);
		print_num (nbr % base_num, base);
	}
	else
		print_num (nbr % base_num, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_num;

	base_num = check_base (base);
	if (base_num == 0)
		return ;
	change_base (base_num, nbr, base);
}
