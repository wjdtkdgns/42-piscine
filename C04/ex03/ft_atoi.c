/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:06:57 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 14:27:05 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rm_blank(char *str, int *idx)
{
	while (str[*idx])
	{
		if (str[*idx] == '\r' || str[*idx] == '\t' || str[*idx] == '\n')
			(*idx)++;
		else if (str[*idx] == '\v' || str[*idx] == '\f' || str[*idx] == ' ')
			(*idx)++;
		else
			break ;
	}	
}

int	ft_atoi(char *str)
{
	int	idx;
	int	negative;
	int	num;

	idx = 0;
	negative = 1;
	num = 0;
	rm_blank(str, &idx);
	while (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			negative *= -1;
		idx++;
	}
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		num = num * 10 + (str[idx] - '0');
		idx++;
	}
	return (negative * num);
}
