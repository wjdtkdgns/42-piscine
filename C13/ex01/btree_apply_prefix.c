#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	applyf (root->item);
	if (root->left)
		btree_apply_prefix (root->left, applyf);
	if (root->right)
		btree_apply_prefix (root->right, applyf);
}