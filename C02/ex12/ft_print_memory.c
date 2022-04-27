/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:35:17 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 14:21:32 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	convert_hexa(unsigned char str)
{
	char	ten;
	char	one;

	ten = str / 16;
	one = str % 16;
	if (ten >= 10)
	{
		ten += 39 + '0';
		write(1, &ten, 1);
	}
	else
	{
		ten += '0';
		write (1, &ten, 1);
	}
	if (one >= 10)
	{
		one += 39 + '0';
		write(1, &one, 1);
	}
	else
	{
		one += '0';
		write (1, &one, 1);
	}
}

void	print_str(char *address, int length)
{
	int	idx;

	idx = 0;
	while (idx < length)
	{
		if (32 <= address[idx] && address[idx] < 127)
			write (1, &(address[idx]), 1);
		else
			write (1, ".", 1);
		idx++;
	}
	if (length < 16)
		write (1, ".", 1);
}

void	not_16(int idx)
{
	if (idx <= 16)
	{
		write (1, "00", 2);
		if (idx % 2 == 0)
			write (1, " ", 1);
		while (idx < 16)
		{
			idx++;
			write (1, "  ", 2);
			if (idx % 2 == 0)
				write (1, " ", 1);
		}
	}
}

void	print_memory_address(long long long_addr, int idx)
{
	char	last_num;

	idx += 1;
	while (idx <= 16)
	{
		print_memory_address (long_addr / 16, idx);
		idx = 17;
	}
	if (long_addr % 16 >= 10)
	{
		last_num = long_addr % 16 + 39 + '0';
		write(1, &last_num, 1);
	}
	else
	{
		last_num = long_addr % 16 + '0';
		write(1, &last_num, 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		idx;
	char	*address;

	address = (char *)addr;
	while (size > 0)
	{
		print_memory_address ((long long)address, 0);
		write (1, ": ", 2);
		idx = 1;
		while (idx <= 16 && address[idx - 1])
		{
			convert_hexa(address[idx - 1]);
			if (idx % 2 == 0)
				write (1, " ", 1);
			idx++;
		}
		not_16 (idx);
		print_str (address, idx - 1);
		write (1, "\n", 1);
		if (size < 16)
			break ;
		size -= 16;
		address += 16;
	}
	return (addr);
}
