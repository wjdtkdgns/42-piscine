/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:19:13 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/16 13:21:35 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_print_line(char left_end, char mid, char right_end, int width)
{
	int	idx;

	idx = 0;
	ft_putchar (left_end);
	if (width - 2 > 0)
	{
		while (idx < width - 2)
		{
			ft_putchar (mid);
			idx++;
		}
	}
	if (width > 1)
		ft_putchar (right_end);
	ft_putchar ('\n');
}

void	rush(int x, int y)
{
	int	idx;

	if (x <= 0 || y <= 0)
		return ;
	idx = 0;
	ft_print_line ('o', '-', 'o', x);
	if (y - 2 > 0)
	{
		while (idx < y - 2)
		{
			ft_print_line('|', ' ', '|', x);
			idx++;
		}
	}
	if (y > 1)
		ft_print_line ('o', '-', 'o', x);
}
