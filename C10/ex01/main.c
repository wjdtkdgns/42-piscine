/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:27:58 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/26 13:27:59 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<libgen.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_error_print(char *name, char *addr)
{
	ft_putstr (basename(addr));
	ft_putstr (": ");
	ft_putstr (name);
	ft_putstr (": ");
	ft_putstr (strerror(errno));
	ft_putstr ("\n");
	errno = 0;
}	

void	print_file(int fd, char *name, char *addr)
{
	char	buf;

	while (read (fd, &buf, 1))
	{
		if (errno)
		{
			ft_error_print (name, addr);
			return ;
		}
		else
		{
			write (1, &buf, 1);
		}
	}
}	

int	main(int argc, char *argv[])
{
	int	idx;
	int	fd;

	if (argc == 1)
		print_file (0, 0, argv[0]);
	idx = 1;
	while (idx < argc)
	{
		fd = open (argv[idx], O_RDONLY);
		if (fd != -1)
		{
			print_file (fd, argv[idx], argv[0]);
			close (fd);
		}
		else
		{
			ft_error_print (argv[idx], argv[0]);
		}
		idx++;
	}
}
