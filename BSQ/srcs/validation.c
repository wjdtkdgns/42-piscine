/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:46:37 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 20:11:51 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_valid_info(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == line[len - 2] || line[len - 1] == line[len - 3])
		return (0);
	if (line[len - 2] == line[len - 3])
		return (0);
	if (!ft_is_printable(line[len - 1]) || !ft_is_printable(line[len - 2]))
		return (0);
	if (!ft_is_printable(line[len - 3]))
		return (0);
	return (1);
}

int	ft_is_valid_map(char *str, t_map_info *info)
{
	char	*line_start;

	line_start = str;
	while (*str)
	{
		if (*str == '\n')
		{
			if (str - line_start != info -> width)
				return (0);
			else
			{
				str++;
				if (*str == 0)
					break ;
				line_start = str;
			}
		}
		if (*str != info -> empty && *str != info -> obstacle)
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_is_valid_malloc_info(t_map_info *map)
{
	if (!map)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}

int	ft_is_valid_malloc_ans(t_ans_info *ans, t_map_info *map)
{
	if (!ans)
	{
		write(2, "map error\n", 10);
		free (map);
		return (0);
	}
	return (1);
}

int	ft_is_valid_height(char *str, t_map_info *info)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '\n')
			count++;
		str++;
	}
	if (count != info -> line)
		return (0);
	return (1);
}
