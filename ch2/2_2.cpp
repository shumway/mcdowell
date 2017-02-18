#include <iostream>
#include <forward_list>

int FromEnd(const std::forward_list<int>& list, int k) {
  auto iter = list.begin();
  for (int i = 0; i <= k; ++i) {
    if (iter == list.end()) {
      return -1;
    }
    ++iter;
  } 
  auto slow = list.begin();
  while (iter != list.end()) {
    ++iter;
    ++slow;
  }
  return *slow;
}

int main() {
  std::forward_list<int> list { 3, 1, 4, 1, 5, 9 };

  std::cout << "End: " << FromEnd(list, 0) << " (9)" << std::endl;
  std::cout << "1st from end: " << FromEnd(list, 1) << " (5)" << std::endl;
  std::cout << "2nd from end: " << FromEnd(list, 2) << " (1)" << std::endl;
  std::cout << "3rd from end: " << FromEnd(list, 3) << " (4)" << std::endl;
  std::cout << "4th from end: " << FromEnd(list, 4) << " (1)" << std::endl;
  std::cout << "5th from end: " << FromEnd(list, 5) << " (3)" << std::endl;
  std::cout << "6th from end: " << FromEnd(list, 6) << " (-1)" << std::endl;
}
