/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:04:50 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/01 13:04:52 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>

void	ft_putstr(char *str);
void	ft_print_multi(char *name);
void	ft_print_offset_error(char *addr, char *str);
void	ft_error_print(char *name, char *addr);
int		ft_is_correct_option(int argc, char **argv);
void	ft_print_preset(int idx, int argc, char **argv, int multi);

#endif
