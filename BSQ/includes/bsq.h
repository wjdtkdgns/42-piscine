/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:12:23 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/30 12:12:25 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_MALLOC_LEN 1000000001

typedef struct s_map_info
{
	int		line;
	int		width;
	char	obstacle;
	char	empty;
	char	full;
}	t_map_info;

typedef struct s_ans
{
	int	max_idx;
	int	len;
}	t_ans_info;

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_is_printable(char str);
int		ft_atoi(char *str);
int		ft_calc_width(char *temp, int map_width);

int		ft_is_valid_info(char *line);
int		ft_is_valid_map(char *str, t_map_info *info);
int		ft_is_valid_malloc_info(t_map_info *map);
int		ft_is_valid_malloc_ans(t_ans_info *ans, t_map_info *map);
int		ft_is_valid_height(char *str, t_map_info *info);

int		ft_set_info(t_map_info *info, char *line);
int		ft_read_firstline(int fd, t_map_info *info);
char	*ft_make_map(char *temp, t_map_info *info);
char	*ft_read_otherlines(int fd, t_map_info *info);
char	*ft_read_map(int fd, t_map_info *info);

void	ft_print_ans(char *map, t_map_info *info);

int		min(int *map, int idx, int width);
void	ft_accumulate(int *map, int width, int height);
void	ft_find_max(int *map, t_ans_info *ans, int width, int height);
void	ft_mark_max(char *map, t_map_info *info, t_ans_info *ans);
int		ft_find_largest(char *map, t_map_info *info, t_ans_info *ans);

#endif
