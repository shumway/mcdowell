#include <iostream>
#include <forward_list>
#include <unordered_set>

void HashedRemoveDuplicates(std::forward_list<int>& list) {
  std::unordered_set<int> visited;
  auto iter = list.begin();
  auto prev = iter;
  while (iter != list.end()) {
    if (visited.count(*iter)) {
      ++iter;
      list.erase_after(prev);
    }
    else {
     visited.insert(*iter);
     prev = iter;
     ++iter;
    }
  }
}

void InPlaceRemoveDuplicates(std::forward_list<int>& list) {
  auto iter = list.begin();
  while (iter != list.end()) {
    int value = *iter;
    auto fast = iter;
    auto prev = iter;
    ++fast;
    while (fast != list.end()) {
      if (*fast == value) {
        list.erase_after(prev);
      }
      else {
        prev = fast;
      }
      ++fast;
    }
    ++iter;
  }
}

void Print(const std::forward_list<int> list) {
  for (auto& i: list) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int main() {  

  std::forward_list<int> original {
      3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9
  };
  std::cout << "Original list:" << std::endl;
  Print(original);

  auto test1 = original;
  HashedRemoveDuplicates(test1);
  std::cout << "FastRemoveDuplicates:" << std::endl;
  Print(test1);

  auto test2 = original;;
  InPlaceRemoveDuplicates(test2);
  std::cout << "InPlaceRemoveDuplicates:" << std::endl;
  Print(test2);

  auto test3 = original;;
  test3.sort();
  test3.unique();
  std::cout << "std sort and unique:" << std::endl;
  Print(test3);
}

