/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:26:27 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/03 16:26:42 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_error(char *name, char *addr)
{
	ft_putstr(basename(addr));
	ft_putstr(": ");
	ft_putstr(name);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}

void	print_error_bad_file(char *name, char *addr)
{
	ft_putstr(basename(addr));
	ft_putstr(": ");
	ft_putstr(name);
	ft_putstr(": ");
	ft_putstr(strerror(9));
	ft_putstr("\n");
	errno = 0;
}
