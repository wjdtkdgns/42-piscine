/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:25:04 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/05/03 16:25:21 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

t_hexdump	*ft_init_hexdump(void)
{
	t_hexdump	*info;

	info = (t_hexdump *)malloc(sizeof(t_hexdump));
	info->prev = ft_init_with_null(17);
	info->buffer = ft_init_with_null(17);
	info->duplicated = 0;
	info->file_len = 0;
	info->is_16_printed = 0;
	info->offset = 0;
	info->name = 0;
	info->addr = 0;
	return (info);
}

void	ft_set_name(t_hexdump *info, char *name, char *addr)
{
	info->name = name;
	info->addr = basename(addr);
}

void	ft_free_info_elem(t_hexdump *info)
{
	free(info->prev);
	free(info->buffer);
	free(info);
}

char	*ft_init_with_null(int size)
{
	int		idx;
	char	*result;

	result = (char *)malloc(size);
	if (!result)
		return (0);
	idx = 0;
	while (idx < size)
	{
		result[idx] = '\0';
		idx++;
	}
	return (result);
}
