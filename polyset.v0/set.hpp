#include "searchable_bag.hpp"
#include "bag.hpp"

class set : public searchable_bag
{
	private:
		searchable_bag* _bag;
	public:
		set(searchable_bag& bag);
		set(const set& other);
		~set();
		set& operator=(const set& other);

		void insert (int num);
		void insert (int *array, int size);
		void print() const;
		void clear();

		bool has(int num) const;

		searchable_bag& get_bag();

};


