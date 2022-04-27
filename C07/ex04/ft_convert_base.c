/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:47:33 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/21 13:47:55 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);
int	ft_atoi_base(char *str, char *base, int base_length);

int	converted_strlen(long long num, int base_length)
{
	int	length;

	length = 1;
	while (num / base_length > 0)
	{
		length++;
		num /= base_length;
	}
	return (length);
}

char	convert_char(int num, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (num == idx)
			return (base[idx]);
		idx++;
	}
	return (0);
}

char	*convert_10_baseto(long long orgin_num, char *base, int base_length)
{
	int		negative;
	int		converted_length;
	char	*converted_num_str;
	int		idx;

	negative = 0;
	if (orgin_num < 0)
	{
		orgin_num *= -1;
		negative = 1;
	}
	converted_length = converted_strlen(orgin_num, base_length);
	converted_num_str = (char *)malloc(converted_length + 1 + negative);
	idx = converted_length - 1 + negative;
	while (orgin_num / base_length > 0)
	{
		converted_num_str[idx] = convert_char(orgin_num % base_length, base);
		orgin_num /= base_length;
		idx--;
	}
	converted_num_str[idx] = convert_char(orgin_num % base_length, base);
	converted_num_str[converted_length + negative] = 0;
	if (negative)
		converted_num_str[0] = '-';
	return (converted_num_str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_length;
	int		to_length;
	int		base10_num;
	char	*rtn_str;

	from_length = check_base(base_from);
	to_length = check_base(base_to);
	if (from_length == 0 || to_length == 0)
		return (0);
	base10_num = ft_atoi_base(nbr, base_from, from_length);
	rtn_str = convert_10_baseto(base10_num, base_to, to_length);
	return (rtn_str);
}
