/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:15:46 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/19 19:19:21 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	is_bigger(char *argv[], int first, int second)
{
	int	idx;

	idx = 0;
	while (argv[first][idx] || argv[second][idx])
	{
		if (argv[first][idx] > argv[second][idx])
			return (1);
		else if (argv[first][idx] < argv[second][idx])
			return (0);
		idx++;
	}
	return (0);
}

void	print_str(char *str[], int argc)
{
	int	idx;
	int	idx2;

	idx = 1;
	while (idx < argc)
	{
		idx2 = 0;
		while (str[idx][idx2])
		{
			write (1, &str[idx][idx2], 1);
			idx2++;
		}
		idx++;
		write (1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	int		idx;
	int		idx2;
	char	*str;

	idx = 1;
	while (idx < argc - 1)
	{
		idx2 = idx + 1;
		while (idx2 < argc)
		{
			if (is_bigger (argv, idx, idx2))
			{
				str = argv[idx];
				argv[idx] = argv[idx2];
				argv[idx2] = str;
			}
			idx2++;
		}
		idx++;
	}
	print_str (argv, argc);
}
