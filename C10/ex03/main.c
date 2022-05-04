/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:25:39 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/03 16:25:48 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	g_c_flag;
int	g_one_of_fd_not_valid;

void	ft_hexdump(t_hexdump *info, int fd)
{
	while (read(fd, &(info->buffer[(info->file_len) % 16]), 1))
	{
		g_one_of_fd_not_valid = 1;
		if (errno)
		{
			print_error(info->name, info->addr);
			break ;
		}
		if (info->file_len % 16 == 15)
		{
			ft_print_full16(info);
			ft_strncpy(info->prev, info->buffer, 16);
			free(info->buffer);
			info->buffer = ft_init_with_null(17);
			info->offset += 16;
		}
		(info->file_len)++;
	}
}

void	ft_stdin(t_hexdump *info)
{
	while (read(0, &(info->buffer[(info->file_len) % 16]), 1))
	{
		g_one_of_fd_not_valid = 1;
		if (errno)
		{
			print_error(info->name, info->addr);
			break ;
		}		
		if (info->file_len % 16 == 15)
		{
			ft_print_full16(info);
			ft_strncpy(info->prev, info->buffer, 16);
			free(info->buffer);
			info->buffer = ft_init_with_null(17);
			info->offset += 16;
		}
		(info->file_len)++;
	}
}

void	ft_read_files(t_hexdump *info, int argc, char *argv[])
{
	int	fd;
	int	idx;

	idx = g_c_flag;
	while (++idx < argc)
	{
		fd = open(argv[idx], O_RDONLY);
		if (fd == -1)
			print_error(argv[idx], argv[0]);
		else
		{
			ft_set_name(info, argv[idx], argv[0]);
			ft_hexdump(info, fd);
		}
	}
	if (!g_one_of_fd_not_valid)
	{
		print_error_bad_file(argv[argc - 1], argv[0]);
	}
}

int	main(int argc, char *argv[])
{
	t_hexdump	*info;

	g_one_of_fd_not_valid = 0;
	info = ft_init_hexdump();
	if (argc > 1 && ft_is_cflag(argv[1]))
		g_c_flag = 1;
	if (argc == 1 + g_c_flag)
		ft_stdin(info);
	else
		ft_read_files(info, argc, argv);
	if ((info->file_len) % 16 != 0)
	{
		ft_print_index(info->offset, g_c_flag, 0);
		ft_print_hex(info->buffer, g_c_flag);
		ft_print_string(info->buffer, g_c_flag);
		ft_putchar('\n');
	}
	if ((info->file_len) % 16 != 0 || info->is_16_printed)
	{
		ft_print_index(info->file_len, g_c_flag, 0);
		ft_putchar('\n');
	}
	ft_free_info_elem(info);
	return (0);
}
