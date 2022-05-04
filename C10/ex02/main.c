/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:41:26 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/30 17:05:40 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	g_multi = 0;

int	ft_atoi(char *str)
{
	int	idx;
	int	num;

	idx = 0;
	num = 0;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		num = num * 10 + (str[idx] - '0');
		idx++;
	}
	return (num);
}

void	ft_tail(int fd, int len)
{
	char	*buf;
	int		idx;
	int		start_idx;

	buf = (char *)malloc(len);
	idx = -1;
	if (len == 0)
		return ;
	else
	{
		while (read(fd, &buf[(++idx % len)], 1))
			if (errno)
				return ;
		start_idx = idx % len;
		if (idx >= len)
			write(1, buf + start_idx, len - start_idx);
		write(1, buf, start_idx);
		g_multi = 1;
	}
}

int	main(int argc, char *argv[])
{
	int	idx;
	int	fd;

	if (argc == 3)
		ft_tail (0, ft_atoi(argv[2]));
	else if (argc > 3)
	{
		idx = 3;
		while (idx < argc)
		{
			errno = 0;
			fd = open (argv[idx], O_RDONLY);
			if (fd != -1)
			{
				ft_print_preset (idx, argc, argv, g_multi);
				ft_tail (fd, ft_atoi(argv[2]));
				close (fd);
			}
			else
				ft_error_print (argv[idx], argv[0]);
			idx++;
		}
	}
}
