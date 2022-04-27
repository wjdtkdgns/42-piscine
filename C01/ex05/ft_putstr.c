/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:10:39 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/14 18:13:11 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putstr(char *str)
{
	int		count;
	char	letter;

	count = 0;
	while (str[count])
	{
		letter = str[count];
		write(1, &letter, 1);
		count++;
	}
}
