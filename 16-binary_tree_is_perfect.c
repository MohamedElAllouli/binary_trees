#include "binary_trees.h"
unsigned char leaf_is(const binary_tree_t *node);
size_t d_epth(const binary_tree_t *tree);
const binary_tree_t *leaf_get(const binary_tree_t *tree);
int recursive_is_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
/**
 * leaf_is - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 * Return: the node is a leaf, 1, otherwise, 0.
 */
unsigned char leaf_is(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
/**
 * d_epth - Returns the depth of a given node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 * Return: depth of node.
 */
size_t d_epth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + d_epth(tree->parent) : 0);
}
/**
 * leaf_get - get a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *leaf_get(const binary_tree_t *tree)
{
	if (leaf_is(tree) == 1)
		return (tree);
	return (tree->left ? leaf_get(tree->left) : leaf_get(tree->right));
}
/**
 * recursive_is_perfect - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: 1 If the tree is perfect, otherwise 0.
 */
int recursive_is_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (leaf_is(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (recursive_is_perfect(tree->left, leaf_depth, level + 1) &&
		recursive_is_perfect(tree->right, leaf_depth, level + 1));
}
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return:  0 If tree is NULL or not perfect, Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_is_perfect(tree, d_epth(leaf_get(tree)), 0));
}
