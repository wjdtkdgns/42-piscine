/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:27:19 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/03 16:27:33 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	ft_is_printable(unsigned char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

int	ft_is_equal(char *c1, char *c2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (c1[i] != c2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_cflag(char *str)
{
	if (str[0] == '-' && str[1] == 'C')
		return (1);
	return (0);
}
