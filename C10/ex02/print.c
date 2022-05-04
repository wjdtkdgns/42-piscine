/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:42:22 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/27 16:42:24 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

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

void	ft_print_preset(int idx, int argc, char **argv, int multi)
{
	if (argc > 4)
	{
		if (multi == 1)
			ft_putstr ("\n");
		ft_putstr ("==> ");
		ft_putstr (argv[idx]);
		ft_putstr (" <==\n");
	}
}
