/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:11:39 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/20 13:22:07 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	dest_length;
	unsigned int	src_length;

	idx = 0;
	dest_length = 0;
	src_length = 0;
	while (dest[dest_length])
		dest_length++;
	while (src[src_length])
		src_length++;
	if (size <= dest_length)
		return (src_length + size);
	while (src[idx] && idx < size - dest_length - 1)
	{
		dest[dest_length + idx] = src[idx];
		idx++;
	}
	dest[dest_length + idx] = '\0';
	return (dest_length + src_length);
}	
