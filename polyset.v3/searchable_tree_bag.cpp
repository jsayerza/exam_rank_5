#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : bag(), tree_bag(other) {}
searchable_tree_bag::~searchable_tree_bag(){}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
	{
		tree_bag::operator=(other);
	}
	return (*this);
}

bool searchable_tree_bag::has(int number) const
{
	return (has_node(tree, number));
}

bool searchable_tree_bag::has_node(node *current, int number) const
{
	if (current == NULL)
		return (false);
	if (current->value == number)
		return (true);
	if (current->value > number)
		return (has_node(current->l, number));
	else
		return (has_node(current->r, number));
}
