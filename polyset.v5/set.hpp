#pragma once

#include "bag.hpp"
#include "searchable_bag.hpp"

class set : public searchable_bag
{
	private:
		searchable_bag* _bag;
	public:
		set(searchable_bag& bag);
		set(const set& other);
		~set();
		set& operator=(const set& other);

		bool has(int number) const;

		void insert (int number);
		void insert (int *array, int size);
	 	void print() const;
		void clear();

		searchable_bag& get_bag() const;
};
