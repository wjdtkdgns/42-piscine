#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*ans;
	void	*temp;

	ans = 0;
	if (root == 0)
		return (0);
	if (cmpf (root -> item, data_ref) == 0)
		return (root -> item);
	if (root -> left)
	{
		temp = btree_search_item(root -> left, data_ref, cmpf);
		if (temp != 0)
			ans = temp;
	}
	if (root -> right)
	{
		temp = btree_search_item(root -> right, data_ref, cmpf);
		if (temp != 0)
			ans = temp;
	}
	return (ans);
}