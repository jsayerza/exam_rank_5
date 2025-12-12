#pragma once

#include "bag.hpp"
#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag* _bag;
	public:
		set(searchable_bag& bag);
		set(const set& other);
		~set();
		set& operator=(const set& other);

		bool has(int num) const;
		searchable_bag& get_bag();

		void insert(int num);
		void insert(int *array, int size);
		void print() const;
		void clear();

};
