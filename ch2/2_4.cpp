#include <iostream>
#include <forward_list>

void Partition(std::forward_list<int>& list, int p) {
  auto iter = list.begin();
  // Pass through thelist, putting low values at the front
  auto prev = iter;
  while (iter != list.end()) {
    if (*iter < p && iter != list.begin()) {
      list.push_front(*iter);
      ++iter;
      list.erase_after(prev);
    }
    else {
      prev = iter;
      ++iter;
    }
  }
}

void Print(const std::forward_list<int>& list) {
  for (int i: list) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::forward_list<int> list { 3, 5, 8, 5, 10, 2, 1 };
  Print(list);
  Partition(list, 5);
  Print(list);
}
