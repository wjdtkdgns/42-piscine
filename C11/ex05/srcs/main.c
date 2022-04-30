/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:40:55 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:40:57 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft.h"

void	calc(int num1, char op, int num2)
{
	void	(*opers[5])(int, int);

	opers[0] = &plus;
	opers[1] = &minus;
	opers[2] = &multi;
	opers[3] = &div;
	opers[4] = &mod;
	if (op == '+')
		opers[0](num1, num2);
	if (op == '-')
		opers[1](num1, num2);
	if (op == '*')
		opers[2](num1, num2);
	if (op == '/')
		opers[3](num1, num2);
	if (op == '%')
		opers[4](num1, num2);
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		num1;
	char	op;
	int		num2;

	if (argc != 4)
		return (0);
	if (!is_valid_oper(argv[2]))
	{
		write (1, "0\n", 2);
		return (0);
	}
	num1 = ft_atoi(argv[1]);
	op = argv[2][0];
	num2 = ft_atoi(argv[3]);
	if (num2 == 0 && op == '/')
	{
		write (1, "Stop : division by zero\n", 24);
		return (0);
	}
	else if (num2 == 0 && op == '%')
	{
		write (1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	calc(num1, op, num2);
}
