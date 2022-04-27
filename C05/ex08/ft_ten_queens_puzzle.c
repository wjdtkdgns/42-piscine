/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghjeo <sanghjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:01:52 by sanghjeo          #+#    #+#             */
/*   Updated: 2022/04/18 18:02:17 by sanghjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rm_board(int board[][10], int cur_x, int cur_y, int ch_mark)
{
	int	idx;

	idx = -9;
	while (idx < 10)
	{
		if (0 <= cur_x + idx && cur_x + idx <= 9)
			if (0 <= cur_y + idx && cur_y + idx <= 9)
				board[cur_x + idx][cur_y + idx] += ch_mark;
		if (0 <= cur_x + idx && cur_x + idx <= 9)
			if (0 <= cur_y - idx && cur_y - idx <= 9)
				board[cur_x + idx][cur_y - idx] += ch_mark;
		if (0 <= cur_x + idx && cur_x + idx <= 9)
			board[cur_x + idx][cur_y] += ch_mark;
		if (0 <= cur_y + idx && cur_y + idx <= 9)
				board[cur_x][cur_y + idx] += ch_mark;
		idx++;
	}
}

int	set_curqueen(int board[][10], int cur_x, int cur_y, char *stack)
{
	int	idx;

	idx = 0;
	stack[cur_y] = cur_x + '0';
	if (cur_y == 9)
	{
		while (idx < 10)
		{
			write (1, &(stack[idx]), 1);
			idx++;
		}
		write (1, "\n", 1);
		return (1);
	}
	rm_board (board, cur_x, cur_y, 1);
	return (0);
}

int	set_queen(int board[][10], int cur_x, int cur_y, char *stack)
{
	int	rtn;
	int	next_x;

	if (set_curqueen(board, cur_x, cur_y, stack) == 1)
		return (1);
	rtn = 0;
	next_x = 0;
	while (next_x < 10)
	{	
		if (board[next_x][cur_y + 1] == 0)
			rtn += set_queen (board, next_x, cur_y + 1, stack);
		next_x++;
	}
	rm_board (board, cur_x, cur_y, -1);
	return (rtn);
}

void	init(int board[][10])
{
	int		x;
	int		y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			board[x][y] = 0;
			y++;
		}
		x++;
	}	
}

int	ft_ten_queens_puzzle(void)
{
	int		board[10][10];
	int		x_idx;
	int		ans;
	char	stack[10];

	init(board);
	x_idx = 0;
	ans = 0;
	while (x_idx < 10)
	{
		ans += set_queen(board, x_idx, 0, stack);
		x_idx++;
	}
	return (ans);
}
