/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:38:51 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/28 11:39:40 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	plus(int a, int b);
void	minus(int a, int b);
void	multi(int a, int b);
void	div(int a, int b);
void	mod(int a, int b);

int		ft_atoi(char *str);

int		is_valid_oper(char *oper);

void	ft_putnbr(int nb);

#endif
