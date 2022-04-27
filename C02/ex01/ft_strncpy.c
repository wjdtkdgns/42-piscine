/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@.student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:46:57 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/16 13:33:45 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	idx = 0;
	while (idx < n)
	{
		if (idx < len)
			dest[idx] = src[idx];
		else
			dest[idx] = '\0';
		idx++;
	}
	return (dest);
}
