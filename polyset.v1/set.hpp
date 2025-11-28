#ifndef SET_HPP
# define SET_HPP

# include "./subject/searchable_bag.hpp"

class set : public searchable_bag 
{
	private:
		searchable_bag* _bag;
	public:
		set(searchable_bag& bag);
		set(const set& other);
		~set();
		set& operator=(const set& other);

		void insert(int value);
		void insert(int *array, int size);
		void print() const;
		void clear();

		bool has(int value) const;
		searchable_bag& get_bag() const;
};

#endif