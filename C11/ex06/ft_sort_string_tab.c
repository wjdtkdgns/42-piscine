/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:42:08 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:42:10 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
{
	int		len;
	int		idx;
	int		idx2;
	char	*str;

	len = 0;
	while (tab[len])
		len++;
	idx = 0;
	while (idx < len - 1)
	{
		idx2 = idx + 1;
		while (idx2 < len)
		{
			if (is_bigger (tab, idx, idx2))
			{
				str = tab[idx];
				tab[idx] = tab[idx2];
				tab[idx2] = str;
			}
			idx2++;
		}
		idx++;
	}
}
