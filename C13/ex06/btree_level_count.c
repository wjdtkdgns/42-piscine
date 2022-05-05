#include "ft_btree.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	btree_infix06(t_btree *root, int *max, int depth)
{
	if (root -> left)
		btree_infix06 (root -> left, max, depth + 1);
	if (root -> right)
		btree_infix06 (root -> right, max, depth + 1);
	if (*max < depth)
		*max = depth;
}

int	btree_level_count(t_btree *root)
{
	int	max;

	max = 0;
	btree_infix06 (root, &max, 1);
	return (max);
}

