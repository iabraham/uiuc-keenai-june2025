#include <iostream>
using std::string;

template <typename T>
class node{
  T data;
  node<T> *left; 
  node<T> *right; 

public:
  node(T value) : data(value), left(nullptr), right(nullptr) {};

  bool operator<(const node<T> &other) const {
    return data < other.data;
  }

  node<T> *getL() const { return left; }
  node<T> *getR() const { return right; }

  void setL(node<T> *lNode){ left = lNode; }
  void setR(node<T> *rNode){ right = rNode; }


  friend std::ostream& operator<<(std::ostream &os, const node<T> &p){
   os << p.data;
   return os;
  }

};

template <typename T>
class BST {
  node<T> *root;

  void print(node<T> *cursor, int depth){
    if (cursor == NULL)
      return;
    for (int i = 0; i < depth; i++)
      printf(i == depth - 1 ? "|-" : "  ");
    std::cout<< *cursor << std::endl;
    print(cursor->getL(), depth + 1);
    print(cursor->getR(), depth + 1);
  }
  
  void deleteTree(node<T> *cursor){
    if (cursor==nullptr)
      return;
    deleteTree(cursor->getL());
    deleteTree(cursor->getR());
    delete cursor;
  }
  
  public:
  
  BST(){
    root = nullptr; 
  };

  BST(node<T>* root) : root(root) {
    root = root;
  };

  void add_node(node<T> *newNode){
    if (root == nullptr) {
      root = newNode;
    }else{
      node<T> *current = root;
      node<T> *prev = nullptr;
      bool fromLeft; 
      while(current!=nullptr){
        if (*newNode < *current){
          prev = current;
          current = current->getL();
          fromLeft = true;
        } else{
          prev = current;
          current = current->getR();
          fromLeft = false;
        }
      }
      if (fromLeft)
        prev->setL(newNode);
      else
        prev->setR(newNode);
    }
  }

  void print(){
    print(root, 0);
  }

  ~BST(){
    deleteTree(root);
    root = nullptr;
  }
};


class Person{
  private:
      std::string name;
      int age;

  public:
  Person(std::string name, int age) : name(name), age(age) {}
  
  void changeName(std::string newName) {
      name = newName;
  }

  void setAge(int newAge) {
      age = newAge;
  }

  // Overload comparison operator 
  bool operator<(const Person& other) const {
      return age < other.age;
  }
  
  friend std::ostream& operator<<(std::ostream& os, const Person& p){
   os << "(" <<p.name <<", "<<p.age<<")";
   return os;
  }

};
