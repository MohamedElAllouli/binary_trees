#include "binary_trees.h"
/**
 * binary_tree_insert_right - Insert a node as the right-child
 * @parent: the node to insert the right-child in.
 * @value: value to store in the new node.
 * Return: parent is NULL or an error occurs - NULL.
 *         Or - a pointer to the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newone;

	if (parent == NULL)
		return (NULL);
	newone = binary_tree_node(parent, value);
	if (newone == NULL)
		return (NULL);
	if (parent->right != NULL)
	{
		newone->right = parent->right;
		parent->right->parent = newone;
	}
	parent->right = newone;
	return (newone);
}
