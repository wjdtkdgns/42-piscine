/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:18:02 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/16 17:49:01 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	idx2;

	idx = 0;
	idx2 = 0;
	while (dest[idx])
		idx++;
	while (src[idx2])
	{
		dest[idx] = src[idx2];
		idx++;
		idx2++;
	}
	dest[idx] = '\0';
	return (dest);
}
