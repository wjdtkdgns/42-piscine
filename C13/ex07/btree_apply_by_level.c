#include "ft_btree.h"

t_btree	**cur_stack;
t_btree	**next_stack;

void	ft_copy_stack(t_btree **dest, t_btree **src)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (src[idx])
		idx++;
	idx2 = 0;
	while (idx2 < idx)
	{
		dest[idx2] = src[idx2];
		idx2++;
	}
}

void	ft_stack_push(int idx, int node_count, int next_stack_len)
{
	t_btree	**temp;

	temp = (t_btree **)malloc(sizeof(t_btree) * (next_stack_len + 1));
	ft_copy_stack (temp, next_stack);
	free (next_stack);
	next_stack = (t_btree **)malloc(sizeof(t_btree) * (next_stack_len + node_count + 1));
	ft_copy_stack (next_stack, temp);
	if (cur_stack[idx] -> left != 0)
	{
		next_stack[next_stack_len] = cur_stack[idx] -> left;
		next_stack_len++;
	}
	if (cur_stack[idx] -> right != 0)
	{
		next_stack[next_stack_len] = cur_stack[idx] -> right;
		next_stack_len++;
	}
	next_stack[next_stack_len] = 0;
	free (temp);
}

void	ft_push_child_node(int idx)
{
	int	node_count;
	int	next_stack_len;

	node_count = 0;
	if (cur_stack[idx] -> left != 0)
		node_count++;
	if (cur_stack[idx] -> right != 0)
		node_count++;
	next_stack_len = 0;
	while (next_stack[next_stack_len])
		next_stack_len++;
	ft_stack_push (idx, node_count, next_stack_len);
}

void	ft_convert_level()
{
	int	next_stack_len;
	int	idx;

	idx = 0;
	next_stack_len = 0;
	while (next_stack[next_stack_len])
		next_stack_len++;
	free (cur_stack);
	cur_stack = (t_btree **)malloc(sizeof(t_btree) * (next_stack_len + 1));
	while (next_stack[idx])
	{
		cur_stack[idx] = next_stack[idx];
		idx++;
	}
	cur_stack[idx] = 0;
	free (next_stack);
	next_stack = (t_btree **)malloc(sizeof(t_btree));
	next_stack[0] = 0;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	idx;
	int	level;

	cur_stack = (t_btree **)malloc(sizeof(t_btree *) * 2);
	next_stack = (t_btree **)malloc(sizeof(t_btree *));
	cur_stack[0] = root;
	cur_stack[1] = 0;
	next_stack[0] = 0;
	level = 1;
	while (*cur_stack != 0)
	{
		idx = 0;
		while (cur_stack[idx])
		{
			if (idx == 0)
				applyf (cur_stack[idx] -> item, level, 1);
			else
				applyf (cur_stack[idx] -> item, level, 0);
			ft_push_child_node(idx);
			idx++;
		}
		ft_convert_level();
		level++;
	}
}