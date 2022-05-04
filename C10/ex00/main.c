/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:04:04 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/26 14:04:06 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int		file;
	char	buf;

	if (argc == 1)
	{
		ft_putstr ("File name missing.\n");
		return (0);
	}
	else if (argc >= 3)
	{
		ft_putstr ("Too many arguments.\n");
		return (0);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_putstr ("Cannot read file.\n");
		return (0);
	}
	while (read (file, &buf, 1))
		write (1, &buf, 1);
	close (file);
}
