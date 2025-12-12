#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other) {}
searchable_tree_bag::~searchable_tree_bag() {}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
		tree_bag::operator=(other);
	return (*this);
}

bool searchable_tree_bag::has(int num) const
{
	return (has_node(tree, num));
}

bool searchable_tree_bag::has_node(node *current, int num) const
{
	if (current == NULL)
		return (false);
	if (current->value == num)
		return (true);
	if (current->value > num)
		return (has_node(current->l, num));
	else
		return (has_node(current->r, num));
}
