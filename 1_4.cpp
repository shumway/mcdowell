#include <bitset>
#include <cctype>
#include <iostream>
#include <string>

bool TestPermutedPalendrome(const std::string s)
{
  std::bitset<26> letters;
  for (char c: s) {
    if (std::isalpha(c)) {
      letters.flip(std::tolower(c) - 'a');
    }
  }
  return letters.count() <= 1;
}

int main() {
  std::string test = "A man a plan a canal Panama";
  std::cout << test << ": " << TestPermutedPalendrome(test) << std::endl;

  test = "Taco Cat";
  std::cout << test << ": " << TestPermutedPalendrome(test) << std::endl;
  
  test = "Not a palendrome";
  std::cout << test << ": " << TestPermutedPalendrome(test) << std::endl;
}

