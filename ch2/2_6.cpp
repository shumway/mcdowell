#include <iostream>
#include <forward_list>
#include <tuple>

template<typename ListIter>
std::pair<bool, ListIter> is_palendrome(ListIter ibegin, int n);

template<typename List>
bool is_palendrome(const List& test) {
  int n = std::distance(test.begin(), test.end());
  return is_palendrome(test.begin(), n).first;
}

template<typename ListIter>
std::pair<bool, ListIter> is_palendrome(ListIter ibegin, int n) {
  switch (n) {
  case 0:
    return std::make_pair(true, ibegin);
  case 1:
    return std::make_pair(true, ++ibegin);
  case 2:
    return std::make_pair(true, ++(++ibegin));
  }
  auto next = ibegin;
  ++next;
  bool is_inner_palendrome;
  ListIter iend;
  std::tie(is_inner_palendrome, iend) = is_palendrome(next, n - 2);
  bool this_matches = (*ibegin == *iend);
  return std::make_pair(is_inner_palendrome && this_matches, ++iend);
}


int main() {
  std::string test = "rotator";
  std::forward_list<char> testlist(test.begin(), test.end());
  std::cout << test << " is " <<  (is_palendrome(testlist) ? "" : "not ")
            << "a palendrome\n";

  test = "deed";
  testlist = std::forward_list<char>(test.begin(), test.end());
  std::cout << test << " is " <<  (is_palendrome(testlist) ? "" : "not ")
            << "a palendrome\n";

  test = "sonar";
  testlist = std::forward_list<char>(test.begin(), test.end());
  std::cout << test << " is " <<  (is_palendrome(testlist) ? "" : "not ")
            << "a palendrome\n";

}
