#pragma once
#include "searchable_bag.hpp"
#include "tree_bag.hpp"
#include <iostream>

class searchable_tree_bag : public searchable_bag, public tree_bag
{
	private:
		tree_bag* _bag;
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag& other);
		~searchable_tree_bag();
		searchable_tree_bag& operator=(const searchable_tree_bag& other);

		bool has(int num) const;
		bool has_node(node *current, int num) const;
};

