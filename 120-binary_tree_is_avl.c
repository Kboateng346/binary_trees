#include "binary_trees.h"
#include "limits.h"

size_t binheight(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int low, int high);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binheight(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t height_l = 0, height_r = 0;

		height_l= tree->left ? 1 + binheight(tree->left) : 1;
		height_r= tree->right ? 1 + binheight(tree->right) : 1;
		return ((height_l > height_r) ? height_l : height_r);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t height_lhgt, height_rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		height_lhgt = binheight(tree->left);
		height_rhgt = binheight(tree->right);
		diff = height_lhgt > height_rhgt ? height_lhgt - height_rhgt : height_rhgt - height_lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, low, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
