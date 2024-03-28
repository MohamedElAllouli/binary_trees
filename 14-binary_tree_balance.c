#include "binary_trees.h"
/**
 * binary_tree_balance - function that measures
 *			the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL,else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t le = 0, ri = 0;

		le = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		ri = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((le > ri) ? le : ri);
	}
	return (0);
}
