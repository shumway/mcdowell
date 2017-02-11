#include <iostream>
#include <string>
#include <unordered_set>

bool AllUnique(const std::string& s) {
  std::unordered_set<char> visited;
  for (char c: s) {
    if (visited.count(c)) {
      return false;
    }
    visited.insert(c);
  } 
  return true;
}

bool AllUniqueNoStorage(const std::string& s) {
  for (auto iter = s.begin(); iter != s.end(); ++iter) {
    for (auto iter2 = iter + 1; iter2 != s.end(); ++iter2) {
      if (*iter == *iter2) {
        return false;
      }
    }
  }
  return true;
}



int main() {
  std::string test = "the quick brown fox";
  std::cout << test << ": " << AllUnique(test) << std::endl;
  std::cout << test << ": " << AllUniqueNoStorage(test) << std::endl;

  test = "no duplicates";
  std::cout << test << ": " << AllUnique(test) << std::endl;
  std::cout << test << ": " << AllUniqueNoStorage(test) << std::endl;

  test = "abcdefghijklmnopqrstuvwxyz";
  std::cout << test << ": " << AllUnique(test) << std::endl;
  std::cout << test << ": " << AllUniqueNoStorage(test) << std::endl;
}
