/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:42:45 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/20 12:04:18 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*copy_str;
	int		idx;

	src_len = 0;
	while (src[src_len])
		src_len++;
	copy_str = (char *)malloc(src_len + 1);
	idx = 0;
	while (idx < src_len)
	{
		copy_str[idx] = src[idx];
		idx++;
	}
	copy_str[idx] = 0;
	return (copy_str);
}
