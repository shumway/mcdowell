#include <iostream>
#include <string>
#include <algorithm>

bool IsPerm(std::string& s1, std::string& s2) {
  if (s1.size() != s2.size()) {
    return false;
  }
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  return s1 == s2;
}


int main() {
  std::string s1 = "bread";
  std::string s2 = "beard";
  std::cout << s1 << ", " << s2 << ": ";
  std::cout << IsPerm(s1, s2) << std::endl;

  s1 = "bread";
  s2 = "braid";
  std::cout << s1 << ", " << s2 << ": ";
  std::cout << IsPerm(s1, s2) << std::endl;

  s1 = "bread";
  s2 = "bre";
  std::cout << s1 << ", " << s2 << ": ";
  std::cout << IsPerm(s1, s2) << std::endl;

  s1 = "bre";
  s2 = "bread";
  std::cout << s1 << ", " << s2 << ": ";
  std::cout << IsPerm(s1, s2) << std::endl;
}
