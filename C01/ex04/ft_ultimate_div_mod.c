/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:08:42 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/14 18:10:06 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	num1;
	int	num2;

	num1 = *a;
	num2 = *b;
	*a = num1 / num2;
	*b = num1 % num2;
}
