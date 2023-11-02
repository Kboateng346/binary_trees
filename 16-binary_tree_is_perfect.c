#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree ||
		(tree->left != NULL && tree->right == NULL) ||
		(!tree->left && tree->right != NULL))
	return (0);

	if (binary_tree_is_perfect(tree->left) ==
		binary_tree_is_perfect(tree->right) &&
		binary_tree_height(tree->left) ==
		binary_tree_height(tree->right))
	return (1);

	return (0);
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height of
 *
 * Return: size_t height, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (tree->right == NULL && tree->left == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	return (1 + right_height);
}
