#include <iostream>
#include <string>

using namespace std;

int IsRotated(const std::string& orig, const std::string& target) {
  auto big = orig + orig;
  size_t i = big.find(target);
  if (i == std::string::npos) {
    return -1;
  }
  else {
    return i;
  }
}

void Report(const std::string& s, int n) {
  cout << s;
  if (n == -1) {
    cout << " is not rotated" << endl;
  }
  else {
    cout << " is left rotated " << n << " chars" << endl;
  }
}

int main() {

  std::string original = "abcdefghij";

  std::string test1 = "abcdefghij";
  int n1 = IsRotated(original, test1);
  Report(test1, n1);

  std::string test2 = "defghijabc";
  int n2 = IsRotated(original, test2);
  Report(test2, n2);

  std::string test3 = "efghijabce";
  int n3 = IsRotated(original, test3);
  Report(test3, n3);

}
