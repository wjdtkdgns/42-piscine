/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:48:22 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/16 18:13:12 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;
	int	ans;

	idx = 0;
	ans = 0;
	while (s1[idx] || s2[idx])
	{	
		if (s1[idx] != s2[idx])
		{
			ans = s1[idx] - s2[idx];
			return (ans);
		}
		idx++;
	}
	return (ans);
}
