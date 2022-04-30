/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:41:50 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:41:52 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_oper(char *oper)
{
	int	oper_len;

	oper_len = 0;
	while (oper[oper_len])
		oper_len++;
	if (oper_len != 1)
		return (0);
	if (oper[0] != '+' && oper[0] != '-' && oper[0] != '/')
		if (oper[0] != '%' && oper[0] != '*')
			return (0);
	return (1);
}
