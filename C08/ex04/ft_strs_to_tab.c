/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:15:06 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/23 20:00:56 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strcpy(char *str)
{
	int		idx;
	char	*copy;

	idx = 0;
	copy = (char *)malloc(ft_strlen(str) + 1);
	while (str[idx])
	{
		copy[idx] = str[idx];
		idx++;
	}
	copy[idx] = 0;
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			idx;

	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock)
		return (0);
	idx = 0;
	while (idx < ac && av[idx])
	{
		stock[idx].size = ft_strlen(av[idx]);
		stock[idx].str = av[idx];
		stock[idx].copy = ft_strcpy(av[idx]);
		idx++;
	}
	stock[idx].size = 0;
	stock[idx].str = 0;
	stock[idx].copy = 0;
	return (stock);
}
