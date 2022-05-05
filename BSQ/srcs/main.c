/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:09:21 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/04 20:12:48 by jaehjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_bsq(int fd)
{
	char		*map;
	t_map_info	*info;
	t_ans_info	*ans;

	info = (t_map_info *)malloc(sizeof(t_map_info));
	if (!ft_is_valid_malloc_info(info))
		return ;
	ans = (t_ans_info *)malloc(sizeof(t_ans_info));
	if (!ft_is_valid_malloc_ans(ans, info))
		return ;
	map = ft_read_map (fd, info);
	if (map == 0)
	{
		write(2, "map error\n", 10);
		free (info);
		free (ans);
		return ;
	}
	if (ft_find_largest (map, info, ans))
		ft_print_ans (map, info);
	else
		write(2, "map error\n", 10);
	free (map);
	free (ans);
	free (info);
}

void	fd_usercreate_map(int fd)
{
	char	buf;
	char	*temp;
	int		idx;

	idx = 0;
	temp = (char *)malloc(MAX_MALLOC_LEN);
	if (!temp)
		write(2, "map error\n", 10);
	fd = open("./use", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG);
	while (read(0, &buf, 1) > 0)
	{
		if (idx == MAX_MALLOC_LEN - 1)
		{
			write(2, "map error\n", 10);
			return ;
		}
		temp[idx++] = buf;
	}
	write(fd, temp, ft_strlen(temp));
	free(temp);
	close (fd);
	fd = open("./use", O_RDONLY);
	ft_bsq (fd);
	close (fd);
}

int	main(int argc, char *argv[])
{
	int		idx;
	char	fd;

	if (argc == 1)
		fd_usercreate_map (0);
	else
	{
		idx = 1;
		while (idx < argc)
		{
			fd = open (argv[idx], O_RDONLY);
			if (fd == -1)
			{
				write(2, "map error\n", 10);
				idx++;
				continue ;
			}
			ft_bsq (fd);
			close (fd);
			if (idx != argc - 1)
				write(1, "\n", 1);
			idx++;
		}
	}
}
