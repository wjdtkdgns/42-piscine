/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:09:40 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/30 12:09:42 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_printable(char str)
{
	if (str < 32 || str == 127)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	idx;
	int	num;

	idx = 0;
	num = 0;
	if (*str == '-' || *str == 0)
		return (0);
	while ('0' <= str[idx] && str[idx] <= '9' && idx < ft_strlen (str) - 3)
	{
		num = num * 10 + (str[idx] - '0');
		idx++;
	}
	if (idx != ft_strlen (str) - 3)
		return (0);
	return (num);
}

int	ft_calc_width(char *temp, int map_width)
{
	while (temp[map_width] != '\n' && temp[map_width])
		map_width++;
	if (temp[map_width] == 0)
		return (0);
	return (map_width);
}
