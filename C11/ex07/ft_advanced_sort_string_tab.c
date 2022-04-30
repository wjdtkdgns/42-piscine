/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:42:38 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:42:39 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		idx;
	int		idx2;
	char	*str;

	idx = 0;
	while (tab[idx])
	{
		idx2 = 0;
		while (tab[idx2] && tab[idx2 + 1])
		{
			if (cmp (tab[idx2], tab[idx2 + 1]) > 0)
			{
				str = tab[idx2];
				tab[idx2] = tab[idx2 + 1];
				tab[idx2 + 1] = str;
			}
			idx2++;
		}
		idx++;
	}
}
