#include "set.hpp"

set::set(searchable_bag& bag) : _bag(&bag) {}
set::set(const set& other) : _bag(other._bag) {}
set::~set(){}
set& set::operator=(const set& other)
{
	if (this != &other)
	{
		_bag = other._bag;
	}
	return (*this);
}

bool set::has(int number) const
{
	return (_bag->has(number));
}

void set::insert (int number)
{
	_bag->insert(number);
}
void set::insert (int *array, int size)
{
	for (int i = 0; i < size; i++)
		_bag->insert(array[i]);
}
void set::print() const
{
	_bag->print();
}
void set::clear()
{
	_bag->clear();
}

searchable_bag& set::get_bag() const
{
	return (*_bag);
}