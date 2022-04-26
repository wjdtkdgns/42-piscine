/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:43:20 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/14 17:44:25 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_first(int *prev_num, int depth)
{
	int	count;

	count = 0;
	while (count < depth)
	{
		if (prev_num[count] != count)
		{
			return (0);
		}
		count++;
	}
	return (1);
}

void	print_num(int *prev_num, int depth)
{
	int		count;
	char	cur_num;

	count = 0;
	while (count < depth)
	{
		cur_num = prev_num[count] + '0';
		write(1, &cur_num, 1);
		count++;
	}
}

void	diving(int *prev_num, int depth, int cur_depth)
{
	int	cur_num;

	if (cur_depth == 1)
		cur_num = 0;
	else
		cur_num = prev_num[cur_depth - 2] + 1;
	while (cur_num <= (9 + cur_depth - depth))
	{
		prev_num[cur_depth - 1] = cur_num;
		if (depth == cur_depth)
		{
			if (!ft_first(prev_num, depth))
				write(1, ", ", 2);
			print_num(prev_num, depth);
		}
		else
		{
			diving (prev_num, depth, cur_depth + 1);
		}
		cur_num++;
	}
}

void	ft_print_combn(int n)
{
	int	num[9];

	num[0] = 0;
	diving (num, n, 1);
}
