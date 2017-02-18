#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

void Urlify(std::string& s, int n) {
  int nspace = std::count(s.begin(), s.begin() + n, ' ');
  auto iter_r = std::make_reverse_iterator(s.begin() + n);
  auto iter_w = iter_r - 2 * nspace;
  for (; iter_r != s.rend(); ++iter_r) {
    if (*iter_r == ' ') {
      *iter_w++ = '0';
      *iter_w++ = '2';
      *iter_w++ = '%';
    }
    else {
      *iter_w++ = *iter_r;
    }
  }
}


int main() {
  std::string test = "A test string    ";
  std::cout << "'" << test << "': ";
  Urlify(test, 13);
  std::cout << "'" << test << "'" << std::endl;
}
