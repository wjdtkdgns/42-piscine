/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:00:33 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/20 14:39:48 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		idx;
	char	*orgin;
	char	*search;

	idx = 0;
	if (*to_find == '\0')
		return (str);
	while (str[idx])
	{
		orgin = &str[idx];
		search = to_find;
		while (*orgin == *search && *orgin && *search)
		{
			search++;
			orgin++;
		}
		if (*search == 0)
			return (&(str[idx]));
		idx++;
	}
	return (0);
}
