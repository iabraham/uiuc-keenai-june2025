#include<iostream>
#include "bst.hpp"

using std::string;

int main(){
  string names[5] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
  int ages[5] = {30, 25, 22, 28, 35};

  BST<Person> tree;

  node<Person> *cursor = nullptr;
  for (int i=0; i<5; i++){
    Person *p = new Person(names[i], ages[i]);
    cursor = new node<Person>(*p);
    tree.add_node(cursor);
    delete p;
  };

  tree.print();
};

