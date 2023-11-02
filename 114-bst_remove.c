#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *nodeinit);
bst_t *bst_remove_recursive(bst_t *root, bst_t *nodeinit, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root nodeinit of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deletes a nodeinit from a binary search tree.
 * @root: A pointer to the root nodeinit of the BST.
 * @nodeinit: A pointer to the nodeinit to delete from the BST.
 *
 * Return: A pointer to the new root nodeinit after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *nodeinit)
{
	bst_t *parent = nodeinit->parent, *successor = NULL;

	/* No children or right-child only */
	if (nodeinit->left == NULL)
	{
		if (parent != NULL && parent->left == nodeinit)
			parent->left = nodeinit->right;
		else if (parent != NULL)
			parent->right = nodeinit->right;
		if (nodeinit->right != NULL)
			nodeinit->right->parent = parent;
		free(nodeinit);
		return (!parent ? nodeinit->right : root);
	}

	/* Left-child only */
	if (nodeinit->right == NULL)
	{
		if (parent != NULL && parent->left == nodeinit)
			parent->left = nodeinit->left;
		else if (parent != NULL)
			parent->right = nodeinit->left;
		if (nodeinit->left != NULL)
			nodeinit->left->parent = parent;
		free(nodeinit);
		return (!parent ? nodeinit->left : root);
	}

	/* Two children */
	successor = inorder_successor(nodeinit->right);
	nodeinit->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Removes a nodeinit from a binary search tree recursively.
 * @root: A pointer to the root nodeinit of the BST to remove a nodeinit from.
 * @nodeinit: A pointer to the current nodeinit in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root nodeinit after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *nodeinit, int value)
{
	if (nodeinit != NULL)
	{
		if (nodeinit->n == value)
			return (bst_delete(root, nodeinit));
		if (nodeinit->n > value)
			return (bst_remove_recursive(root, nodeinit->left, value));
		return (bst_remove_recursive(root, nodeinit->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a nodeinit from a binary search tree.
 * @root: A pointer to the root nodeinit of the BST to remove a nodeinit from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root nodeinit after deletion.
 *
 * Description: If the nodeinit to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
