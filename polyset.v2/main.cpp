#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"

#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;

  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  t->print();
  a->print();

  for (int i = 1; i < argc; i++) {
    std::cout << "busca a t: " << (atoi(argv[i])) << " --> " << t->has(atoi(argv[i])) << std::endl;
    std::cout << "busca a a: " << (atoi(argv[i])) << " --> " << a->has(atoi(argv[i])) << std::endl;
    std::cout << "busca a t: " << (atoi(argv[i]) - 1) << " --> " << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << "busca a a: " << (atoi(argv[i]) - 1) << " --> " << a->has(atoi(argv[i]) - 1) << std::endl;
  }

  t->clear();
  a->clear();

  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  tmp.print();
  tmp.has(1);

  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
    st.insert(atoi(argv[i]));
    sa.insert(atoi(argv[i]));

    sa.has(atoi(argv[i]));
	// std::cout << "busca a sa: " << (atoi(argv[i])) << " --> " << sa.has(atoi(argv[i])) << std::endl;
	std::cout << "sa: ";
    sa.print();
	std::cout << "sa (get_bag): ";
    sa.get_bag().print();
	std::cout << "st: ";
    st.print();
    sa.clear();
    int tmp_array[] = {1, 2, 3, 4};
    sa.insert(tmp_array, 4);
	std::cout << std::endl;
  }

  return 0;
}
