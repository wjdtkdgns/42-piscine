/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:20:24 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/16 17:49:33 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	unsigned int	idx2;

	idx = 0;
	idx2 = 0;
	while (dest[idx])
		idx++;
	while (src[idx2] && idx2 < nb)
	{
		dest[idx] = src[idx2];
		idx++;
		idx2++;
	}
	dest[idx] = '\0';
	return (dest);
}	
