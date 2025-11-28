#ifndef SEARCHEABLE_ARRAY_BAG_HPP
# define SEARCHEABLE_ARRAY_BAG_HPP

# include "./subject/array_bag.hpp"
# include "./subject/searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag& other);
		~searchable_array_bag();

		searchable_array_bag& operator=(const searchable_array_bag& other);

		virtual bool has(int number) const;

};

#endif