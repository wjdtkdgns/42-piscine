/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:37:23 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:37:26 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sort(int *tab, int length, int (*f)(int, int))
{
	int	idx;
	int	idx2;

	idx = 0;
	while (idx < length - 1)
	{
		idx2 = idx + 1;
		while (idx2 < length)
		{
			if (f (tab[idx], tab[idx2]) > 0)
			{
				return (0);
			}
			idx2++;
		}
		idx++;
	}
	return (1);
}

int	rev(int *tab, int length, int (*f)(int, int))
{
	int	idx;
	int	idx2;

	idx = 0;
	while (idx < length - 1)
	{
		idx2 = idx + 1;
		while (idx2 < length)
		{
			if (f (tab[idx], tab[idx2]) < 0)
			{
				return (0);
			}
			idx2++;
		}
		idx++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (sort(tab, length, f) == 1 || rev(tab, length, f) == 1)
		return (1);
	return (0);
}
