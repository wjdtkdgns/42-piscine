/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:47:35 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/19 16:47:58 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int	idx;

	idx = 0;
	while (argc == 1 && argv[0][idx])
	{
		write (1, &argv[0][idx], 1);
		idx++;
	}
	write (1, "\n", 1);
}
