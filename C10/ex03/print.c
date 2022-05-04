/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:26:12 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/03 16:26:14 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	ft_print_full16(t_hexdump *info)
{
	info->is_16_printed = 1;
	if (ft_is_equal(info->prev, info->buffer))
	{
		if (!(info->duplicated))
			ft_putstr("*\n");
		info->duplicated = 1;
		return ;
	}
	info->duplicated = 0;
	ft_print_index(info->offset, g_c_flag, 0);
	ft_print_hex(info->buffer, g_c_flag);
	ft_print_string(info->buffer, g_c_flag);
	ft_putchar('\n');
}

void	ft_print_index(int idx, int c_flag, int depth)
{
	char	*base;

	base = "0123456789abcdef";
	if (depth == 7 + c_flag)
		return ;
	ft_print_index(idx / 16, c_flag, depth + 1);
	ft_putchar(base[idx % 16]);
}

void	ft_print_hex(char *str, int c_flag)
{
	int		idx;
	char	*base;

	base = "0123456789abcdef";
	if (c_flag == 1)
		ft_putchar(' ');
	idx = 0;
	while (str[idx] && idx < 16)
	{
		ft_putchar(' ');
		ft_putchar(base[(unsigned char)str[idx] / 16]);
		ft_putchar(base[(unsigned char)str[idx] % 16]);
		if (idx == 7 && c_flag == 1)
			ft_putchar(' ');
		idx++;
	}
	while (idx < 16)
	{
		ft_putstr("   ");
		if (idx == 7 && c_flag == 1)
			ft_putchar(' ');
		idx++;
	}
}

void	ft_print_string(char *str, int c_flag)
{
	int	idx;

	if (c_flag == 0)
		return ;
	ft_putstr("  |");
	idx = 0;
	while (str[idx] && idx < 16)
	{
		if (ft_is_printable(str[idx]))
			ft_putchar(str[idx]);
		else
			ft_putchar('.');
		idx++;
	}
	ft_putchar('|');
}
