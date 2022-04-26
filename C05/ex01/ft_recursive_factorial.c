/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:37:43 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 16:38:07 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_recursive_factorial(int nb)
{
	int	num;

	if (nb < 0)
		return (0);
	num = 1;
	if (nb >= 1)
		num = nb * ft_recursive_factorial (nb - 1);
	else if (nb == 0)
		num = 1;
	else
		num = 0;
	return (num);
}
