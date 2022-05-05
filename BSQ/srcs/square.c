/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:06:55 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/30 12:06:57 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min(int *map, int idx, int width)
{
	int	min;

	if (map[idx - 1] > map[idx - width - 1])
		min = map[idx - width - 1];
	else
		min = map[idx - 1];
	if (min > map[idx - width])
		min = map[idx - width];
	return (min);
}

void	ft_accumulate(int *map, int width, int height)
{
	int	idx;

	idx = 0;
	while (idx < height * width)
	{
		if (idx >= width && idx % width != 0 && map[idx] != 0)
			map[idx] = min (map, idx, width) + 1;
		idx++;
	}
}

void	ft_find_max(int *map, t_ans_info *ans, int width, int height)
{
	int	max;
	int	idx;

	max = 0;
	idx = 0;
	while (idx < width * height)
	{
		if (max < map[idx])
		{
			max = map[idx];
			ans -> len = max;
			ans -> max_idx = idx;
		}
		idx++;
	}
}

void	ft_mark_max(char *map, t_map_info *info, t_ans_info *ans)
{
	int	top;
	int	left;
	int	idx;
	int	idx2;

	top = (ans -> max_idx - info -> width * (ans -> len - 1)) / info -> width;
	left = (ans -> max_idx - ans -> len + 1) % info -> width;
	idx = top;
	while (idx < ans -> max_idx / info -> width + 1)
	{
		idx2 = left;
		while (idx2 < ans -> max_idx % info -> width + 1)
		{
			map[idx2 + idx * info -> width] = info -> full;
			idx2++;
		}
		idx++;
	}
}

int	ft_find_largest(char *map, t_map_info *info, t_ans_info *ans)
{
	int	*map_01;
	int	idx;

	map_01 = (int *)malloc(4 * (info -> width * info -> line));
	if (!map_01)
		return (0);
	idx = 0;
	while (map[idx])
	{
		if (map[idx] == info -> empty)
			map_01[idx] = 1;
		else
			map_01[idx] = 0;
		idx++;
	}
	ft_accumulate (map_01, info -> width, info -> line);
	ft_find_max (map_01, ans, info -> width, info -> line);
	ft_mark_max (map, info, ans);
	free (map_01);
	return (1);
}
