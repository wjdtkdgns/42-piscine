/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:48:05 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/21 13:48:28 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	size;
	int	idx;

	size = 0;
	while (base[size])
	{
		idx = size + 1;
		while (base[idx])
		{
			if (base[idx] == base[size])
				return (0);
			idx++;
		}
		if (base[size] == '+' || base[size] == '-')
			return (0);
		if (base[size] == '\r' || base[size] == '\t' || base[size] == '\n')
			return (0);
		else if (base[size] == '\v' || base[size] == '\f' || base[size] == ' ')
			return (0);
		size++;
	}
	if (size <= 1)
		return (0);
	return (size);
}

char	*find_num(char *str)
{
	while (*str)
	{
		if (*str == '\r' || *str == '\t' || *str == '\n')
			str++;
		else if (*str == '\v' || *str == '\f' || *str == ' ')
			str++;
		else
			break ;
	}
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str++;
		else
			break ;
	}
	return (str);
}

int	is_negative(char *str)
{
	int	negative;

	negative = 1;
	while (*str)
	{
		if (*str == '\r' || *str == '\t' || *str == '\n')
			str++;
		else if (*str == '\v' || *str == '\f' || *str == ' ')
			str++;
		else
			break ;
	}
	while (*str)
	{
		if (*str == '-')
			negative *= -1;
		else if (*str != '+')
			break ;
		str++;
	}
	return (negative);
}

int	convert_base(char *base, char *str, int base_length)
{
	int	idx;
	int	num;

	num = 0;
	while (*str)
	{
		idx = 0;
		while (base[idx])
		{
			if (*str == base[idx])
			{
				num = num * base_length + idx;
				break ;
			}
			idx++;
		}
		if (idx == base_length)
			break ;
		str++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base, int base_length)
{
	int		negative;
	char	*start_num;
	int		positive_ans;

	negative = is_negative (str);
	start_num = find_num (str);
	positive_ans = convert_base(base, start_num, base_length);
	return (negative * positive_ans);
}
