#include <cstdlib>
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
  // Set up lists so that list2 connects to list1 at element "6"
  List<int> list1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  List<int> list2 = { 3, 4, 5 };
  auto node1 = list1.before_begin.next;
  auto node2 = list2.before_begin.next;
  for (int i = 1; i < 6; ++i) {
    node1 = node1->next;
  }
  for (int i = 1; i < 3; ++i) {
    node2 = node2->next;
  }
  node2->next = node1;


  // Compare the lengths of the lists.
  node1 = list1.before_begin.next;
  int len1 = 0;
  std::cout << "list 1: ";
  while (node1->next) {
    std::cout << node1->value << " ";
    node1 = node1->next; 
    len1++;
  }
  std::cout << "\n";
  node2 = list2.before_begin.next;
  int len2 = 0;
  std::cout << "list 2: ";
  while (node2->next) {
    std::cout << node2->value << " ";
    node2 = node2->next; 
    len2++;
  }
  std::cout << "\n";
  if (node1 != node2) {
    std::cout << "lists are separate\n";
    return 0;
  }
  auto short_list = (len1 > len2) ? &list2 : &list1;
  auto long_list = (len1 > len2) ? &list1 : &list2;

  // Give the long list a head start.
  auto node_l = long_list->before_begin.next;
  for (int i = 0; i < abs(len1 - len2); ++i) {
    node_l = node_l->next;
  }
  auto node_s = short_list->before_begin.next;
  while (node_l != node_s) {
    node_l = node_l->next;
    node_s = node_s->next;
  }
  std::cout << "Lists join at value " << node_s->value << "\n";
  

}

