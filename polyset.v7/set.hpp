#ifndef SET_HPP
# define SET_HPP

# include <iostrem>
# include <ostream>
# include "searchable_bag.hpp"

class set : public searchable_bag
{
	private:
		searchable_bag* _bag;
	public:
	set(searchable_bag& bag);
	set(const set& other);
	~set();
	set& operator=(const set& other);

	bool has(int num) const;

	void insert (int num);
	void insert (int *array, int size);
	void print() const;
	void clear();

	searchable_bag& get_bag();

};

#endif
