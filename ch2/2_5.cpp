#include <cstdint>
#include <forward_list>
#include <functional>
#include <iostream>

template <class List>
List add_reverse(const List& add1, const List& add2) {
  auto a1 = add1.begin();
  auto a2 = add2.begin();
  List sum;
  auto sum_iter = sum.before_begin();
  bool carry = false;
  while (a1 != add1.end() && a2 != add2.end()) {
    int digit_sum = carry;
    digit_sum += (a1 != add1.end()) ? *a1 : 0u;
    digit_sum += (a2 != add2.end()) ? *a2 : 0u;
    sum_iter = sum.insert_after(sum_iter, digit_sum % 10);
    carry = digit_sum > 9;
    ++a1;
    ++a2;
  }
  if (carry) {
    sum_iter = sum.insert_after(sum_iter, 1);
  }
  return sum;
}

template <class List>
List add_forward(const List& add1, const List& add2) {
  int offset = int(std::distance(add1.begin(), add1.end()))
    - int(std::distance(add2.begin(), add2.end()));
  List sum;
  auto sum_iter = sum.before_begin();
  List carry;
  auto carry_iter = carry.before_begin();
  int i = 0;
  auto a1 = add1.begin();
  auto a2 = add2.begin();
  while (a1 != add1.end() && a2 != add2.end()) {
    int digit_sum = 0;
    if (offset >=0 || i + offset >= 0) {
      digit_sum += *a1;
      ++a1;
    }
    if (offset <=0 || i - offset >= 0) {
      digit_sum += *a2;
      ++a2;
    }
    sum_iter = sum.insert_after(sum_iter, digit_sum % 10);
    if (digit_sum > 9 || !carry.empty()) {
      carry_iter = carry.insert_after(carry_iter, digit_sum > 9);
    }
    ++i;
  }
  if (!carry.empty()) {
    carry_iter = carry.insert_after(carry_iter, 0);
    sum = add_forward(sum, carry);
  }
  return sum;
}

template <class List>
void print_number_forward(const List& num) {
  for (auto d = num.begin(); d != num.end(); ++d) {
    std::cout << int(*d);
  }
}

template <class List>
void print_number_reverse(const List& num) {
  List buffer(num);
  buffer.reverse();
  print_number_forward(buffer);
}


template <class List>
void print_sum(const List& add1, const List& add2, const List& sum,
    std::function<void(const List&)> print_number) {
  print_number(add1);
  std::cout << " + ";
  print_number(add2);
  std::cout << " = ";
  print_number(sum);
  std::cout << "\n";
}

int main() {
  using List = std::forward_list<uint8_t>;
  {
    List add1 { 7, 1, 6 };
    List add2 { 5, 9, 2 };
    auto sum = add_reverse(add1, add2);
    std::cout << "Reverse sum (expect 912)\n";
    std::function<void(const List&)> print_reverse = print_number_reverse<List>;
    print_sum(add1, add2, sum, print_reverse);
  }

  {
    List add1 { 6, 1, 7 };
    List add2 { 2, 9, 5 };
    auto sum = add_forward(add1, add2);
    std::cout << "Forward sum (expect 912)\n";
    std::function<void(const List&)> print_forward = print_number_forward<List>;
    print_sum(add1, add2, sum, print_forward);
  }
}

