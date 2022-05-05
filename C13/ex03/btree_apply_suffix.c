#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0)
		return ;
	if (root->left)
		btree_apply_suffix (root->left, applyf);
	if (root->right)
		btree_apply_suffix (root->right, applyf);
	applyf (root->item);
}