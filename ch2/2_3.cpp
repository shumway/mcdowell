#include <iostream>
#include <initializer_list>
#include <memory>

template<typename T>
class List {
public:

  List(std::initializer_list<T> l) {
    auto iter = l.begin();
    if (iter != l.end()) {
      head = std::make_unique<Node>(*iter);
    }
    ++iter;
    auto prev = head.get();
    for (; iter != l.end(); ++iter) {
      prev->next = std::make_unique<Node>(*iter);
      prev = prev->next.get();
    }
  }

  void Print() {
    auto iter = head.get();
    while (iter) {
      std::cout << iter->value << " ";
      iter = iter->next.get();
    }
    std::cout << std::endl;
  }

  void RemoveFirst(T value) {
    auto iter = head.get();
    Node* prev = nullptr;
    while (iter) {
      if (iter->value == value) {
        auto trash = std::move(prev->next);
        prev->next = std::move(iter->next);
      }
      prev = iter;
      iter = iter->next.get();
    }
  }


  class Node {
  public:
    Node(T v) : value(v) {}
    T value;
    std::unique_ptr<Node> next;
  };

private:
  std::unique_ptr<Node> head;  
};

int main() {
  List<int> list = { 1, 2, 3, 4, 5 };
  std::cout << "Original list:" << std::endl;
  list.Print();
  list.RemoveFirst(3);
  std::cout << "After 3 is removed:" << std::endl;
  list.Print();
}
