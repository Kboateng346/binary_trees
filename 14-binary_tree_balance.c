#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height of
 *
 * Return: size_t height, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (!tree->right && !tree->left))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	return (1 + right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure balance of
 *
 * Return: int balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree || (tree->left == NULL && tree->right == NULL))
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;

	return (left_height - right_height);
}
