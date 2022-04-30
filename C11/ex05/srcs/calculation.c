/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:40:11 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:40:13 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft.h"

void	plus(int a, int b)
{
	int	ans;

	ans = a + b;
	ft_putnbr (ans);
}

void	minus(int a, int b)
{
	int	ans;

	ans = a - b;
	ft_putnbr (ans);
}

void	multi(int a, int b)
{
	int	ans;

	ans = a * b;
	ft_putnbr (ans);
}

void	div(int a, int b)
{
	int	ans;

	ans = a / b;
	ft_putnbr (ans);
}

void	mod(int a, int b)
{
	int	ans;

	ans = a % b;
	ft_putnbr (ans);
}
