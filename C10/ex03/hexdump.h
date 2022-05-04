/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:22:39 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/03 16:24:45 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>

typedef struct s_hexdump {
	char		*name;
	char		*addr;
	char		*prev;
	char		*buffer;
	int			duplicated;
	int			file_len;
	int			is_16_printed;
	int			offset;
}	t_hexdump;

void		ft_print_full16(t_hexdump *hf);
void		ft_print_index(int index, int flag, int depth);
void		ft_print_hex(char *str, int flag);
void		ft_print_string(char *str, int flag);

void		print_error(char *name, char *addr);
void		print_error_bad_file(char *name, char *addr);

void		ft_putchar(unsigned char c);
void		ft_putstr(char *str);
int			ft_strcmp(char *a, char *b);
void		ft_strncpy(char *dst, char *src, int size);
char		*malloc_with_null_init(int size);

int			ft_is_printable(unsigned char c);
int			ft_is_equal(char *c1, char *c2);
int			ft_is_cflag(char *str);

t_hexdump	*ft_init_hexdump(void);
void		ft_set_name(t_hexdump *hf, char *file, char *addr);
void		ft_free_info_elem(t_hexdump *info);
char		*ft_init_with_null(int size);

extern int	g_c_flag;

#endif
