/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:53:41 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/16 12:50:59 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	change_first(char cur_str, int first)
{
	if (first == 0)
		if (cur_str < 'A' || 'Z' < cur_str)
			if (cur_str < 'a' || 'z' < cur_str)
				if (cur_str < '0' || '9' < cur_str)
					return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	idx;
	int	first;

	idx = 0;
	first = 1;
	while (str[idx])
	{
		if (first == 1 && 'a' <= str[idx] && str[idx] <= 'z')
		{
			first = 0;
			str[idx] -= 'a' - 'A';
		}
		else if (first == 1 && '0' <= str[idx] && str[idx] <= '9')
			first = 0;
		else if (first == 1 && 'A' <= str[idx] && str[idx] <= 'Z')
			first = 0;
		else if (first == 0 && 'A' <= str[idx] && str[idx] <= 'Z')
			str[idx] += 'a' - 'A';
		else if (change_first(str[idx], first))
			first = 1;
		idx++;
	}
	return (str);
}
