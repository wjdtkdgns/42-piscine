/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:46:48 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/21 13:47:21 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	ft_strlen(char *str)
{
	int	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}

int	str_length(char **strs, char *sep, int size)
{
	int	idx;
	int	total_length;
	int	sep_length;

	idx = 0;
	total_length = 0;
	while (idx < size)
	{
		total_length += ft_strlen(strs[idx]);
		idx++;
	}
	sep_length = ft_strlen(sep);
	if (size > 0)
		total_length += sep_length * (size - 1);
	return (total_length);
}

void	ft_strcat(char *rtn_str, char *str, int *cur_pos)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		rtn_str[*cur_pos] = str[idx];
		idx++;
		(*cur_pos)++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	char	*rtn_str;
	int		idx;
	int		cur_pos;

	total_length = str_length(strs, sep, size);
	rtn_str = (char *)malloc(total_length + 1);
	idx = 0;
	cur_pos = 0;
	while (idx < size)
	{
		ft_strcat (rtn_str, strs[idx], &cur_pos);
		if (idx != size - 1)
			ft_strcat (rtn_str, sep, &cur_pos);
		idx++;
	}
	rtn_str[total_length] = 0;
	return (rtn_str);
}
