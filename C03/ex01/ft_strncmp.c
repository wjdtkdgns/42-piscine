/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:22:17 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/16 18:20:07 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;
	unsigned int	ans;

	idx = 0;
	ans = 0;
	while ((s1[idx] || s2[idx]) && idx < n)
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
