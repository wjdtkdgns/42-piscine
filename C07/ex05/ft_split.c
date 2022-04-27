/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:31:16 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/23 11:31:40 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	is_charset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	word_cnt(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			count++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
		str++;
	}
	return (count);
}

void	ft_strncpy(char *dest, char *src, int size)
{
	int	idx;

	idx = -1;
	while (++idx < size && *src)
		*(dest++) = *(src++);
	*dest = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**rtn;
	char	*str_start;
	int		idx;

	rtn = (char **)malloc(sizeof(char *) * word_cnt(str, charset) + 1);
	idx = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			str_start = str;
			while (*str && !is_charset(*str, charset))
				str++;
			rtn[idx] = (char *)malloc(str - str_start + 1);
			ft_strncpy(rtn[idx], str_start, str - str_start);
			idx++;
		}
		else
			str++;
	}
	rtn[idx] = 0;
	return (rtn);
}
