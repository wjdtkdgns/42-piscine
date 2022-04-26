/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:09:11 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/19 17:09:35 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	idx;
	int	idx2;

	idx = 1;
	while (idx < argc)
	{
		idx2 = 0;
		while (argv[idx][idx2])
		{
			write (1, &argv[idx][idx2], 1);
			idx2++;
		}
		write (1, "\n", 1);
		idx++;
	}
}
