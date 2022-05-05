/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:07:47 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/05 12:14:34 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_set_info(t_map_info *info, char *line)
{
	int	idx;
	int	line_num;

	idx = 0;
	while (line[idx])
	{
		if (!ft_is_printable(line[idx]))
			return (0);
		idx++;
	}
	line_num = ft_atoi (line);
	if (!line_num || !ft_is_valid_info (line))
		return (0);
	info -> line = line_num;
	info -> empty = line[ft_strlen (line) - 3];
	info -> obstacle = line[ft_strlen (line) - 2];
	info -> full = line[ft_strlen (line) - 1];
	return (1);
}

int	ft_read_firstline(int fd, t_map_info *info)
{
	char	buf;
	int		idx;
	char	*line;

	idx = 0;
	line = (char *)malloc(100000);
	if (!line)
		return (0);
	while (read (fd, &buf, 1) > 0 && idx < 100000)
	{
		if (buf == '\n')
		{
			line[idx] = 0;
			break ;
		}
		line[idx] = buf;
		idx++;
	}
	if (!ft_set_info (info, line))
	{
		free (line);
		return (0);
	}
	free (line);
	return (1);
}

char	*ft_make_map(char *temp, t_map_info *info)
{
	char	*map;
	int		idx;
	int		idx2;

	if (!ft_is_valid_map(temp, info))
		return (0);
	map = (char *)malloc(info -> width * info -> line + 1);
	if (!map)
		return (0);
	idx = 0;
	idx2 = 0;
	while (temp[idx])
	{
		if (temp[idx] != '\n')
		{
			map[idx2] = temp[idx];
			idx++;
			idx2++;
		}
		else
			idx++;
	}
	map[idx2] = 0;
	return (map);
}

char	*ft_read_otherlines(int fd, t_map_info *info)
{
	char	*temp;
	int		map_width;
	char	*map;

	temp = (char *)malloc(MAX_MALLOC_LEN);
	if (!temp)
		return (0);
	if (!(read (fd, temp, MAX_MALLOC_LEN - 1) > 0))
	{
		free (temp);
		return (0);
	}
	map_width = ft_calc_width (temp, 0);
	if (map_width == 0 || !ft_is_valid_height(temp, info))
	{
		free (temp);
		return (0);
	}
	info -> width = map_width;
	map = ft_make_map(temp, info);
	free (temp);
	if (!map)
		return (0);
	return (map);
}

char	*ft_read_map(int fd, t_map_info *info)
{
	char	*map;

	if (!ft_read_firstline(fd, info))
		return (0);
	if (info->line == 100000)
		return (0);
	map = ft_read_otherlines(fd, info);
	if (map == 0)
		return (0);
	return (map);
}
