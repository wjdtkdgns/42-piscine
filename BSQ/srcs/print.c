/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:08:57 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/30 12:08:59 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_ans(char *map, t_map_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info -> width * info -> line)
	{
		write (1, &map[idx], 1);
		if (idx % info -> width == info -> width - 1)
			ft_putstr("\n");
		idx++;
	}
}
