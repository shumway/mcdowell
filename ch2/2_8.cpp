#include <iostream>
#include <initializer_list>
#include <memory>

template<typename T>
class List {
public:

  class Node {
  public:
    Node(T value) 
    : value(value) {
    }
    std::shared_ptr<Node> next;
    T value;
  };

  Node before_begin { 0 };

  List(std::initializer_list<T> init) {
    Node* node = &before_begin;
    for (const auto& t: init) {
      node->next = std::make_shared<Node>(t);
      node = node->next.get();
    }
  }
};



int main() {
  // Set up list with a circular loop to element "7"
  List<int> list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  auto iter1 = list.before_begin.next;
  while (iter1->value != 7) {
    iter1 = iter1->next;
  }
  auto iter2 = iter1;
  while (iter1->next) {
    iter1 = iter1->next;
  }
  iter1->next = iter2;

  // Find the loop by using a fast and slow iterator.
  iter1 = list.before_begin.next;
  iter1 = iter1->next;
  iter2 = list.before_begin.next;
  while (iter1->next && iter1 != iter2) {
    iter1 = iter1->next;
    iter1 = iter1->next ? iter1->next : iter1;
    iter2 = iter2->next;
  }
  if (!iter1->next) {
    return 0;
  }
  int nloop = 1;
  // Measure the loop size.  
  while (iter1->next != iter2) {
    iter1 = iter1->next;
    ++nloop;
  }

  // Start iter1 one loop length ahead.
  iter1 = list.before_begin.next;
  for (int i = 0; i < nloop; ++i) {
    iter1 = iter1->next;
  }
  iter2 = list.before_begin.next;
  while (iter1 != iter2) {
    iter1 = iter1->next;
    iter2 = iter2->next;
  }
  std::cout << "Loop with size " << nloop 
            << " starts at element value " << iter1->value << "\n";
}

