/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:08:23 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/19 17:08:45 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	int	idx;
	int	idx2;

	idx = argc - 1;
	while (idx > 0)
	{
		idx2 = 0;
		while (argv[idx][idx2])
		{
			write (1, &argv[idx][idx2], 1);
			idx2++;
		}
		write (1, "\n", 1);
		idx--;
	}
}
