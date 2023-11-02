#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: A pointer to the node containing an int equal to `value`
 *         NULL if tree is NULL
 *         NULL if no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *nodeinit = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (nodeinit)
	{
		if (value == nodeinit->n)
			return (nodeinit);
		if (value < nodeinit->n)
			nodeinit = nodeinit->left;
		else if (value > nodeinit->n)
			nodeinit = nodeinit->right;
	}

	return (NULL);
}
