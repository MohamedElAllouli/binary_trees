#include "binary_trees.h"
/**
 * binary_tree_insert_left - Inserts  node as a left-child
 * @parent: the node to insert the left-child in.
 * @value: value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Or- a pointer to the new node.
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newone;

	if (parent == NULL)
		return (NULL);

	newone = binary_tree_node(parent, value);
	if (newone == NULL)
		return (NULL);
	if (parent->left != NULL)
	{		newone->left = parent->left;
		parent->left->parent = newone;
	}
	parent->left = newone;
	return (newone);
}
