#include <iostream>
#include <string>

int CountDiffs(
    std::string::const_iterator i1,
    std::string::const_iterator end1,
    std::string::const_iterator i2,
    std::string::const_iterator end2,
    int ndiff) {
  if (ndiff > 1) {
    // Bail early if we have exceded one difference.
    return ndiff;
  } 
  if (i1 == end1) {
    // Done if at end of string one.
    return ndiff + (end2 - i2);
  }
  if (i2 == end2) {
    // Done if at end of string two.
    return ndiff + (end1 - i1);
  }
  if (*i1 == *i2) {
    // Move on if these characters match
    return CountDiffs(i1 + 1, end1, i2 + 1, end2, ndiff);
  }
  // Otherwise take the best of the three edits (replace, delete, or insert)
  return std::min(std::min(
    CountDiffs(i1 + 1, end1, i2 + 1, end2, ndiff + 1),
    CountDiffs(i1 + 1, end1, i2, end2, ndiff + 1)),
    CountDiffs(i1, end1, i2 + 1, end2, ndiff + 1));
}

bool IsOneAwayRecursive(const std::string& s1, const std::string& s2) {
  // This is easily generalized to check for more than one difference
  int ndiff = CountDiffs(s1.begin(), s1.end(), s2.begin(), s2.end(), 0);
  return ndiff <= 1;
}

bool IsOneAway(const std::string& s1, const std::string& s2) {
  if (abs(int(s1.size()) - int(s2.size())) > 1) {
    return false;
  }
  bool used_edit = false;
  auto iter1 = s1.begin();
  auto iter2 = s2.begin();
  for (; iter1 < s1.end() && iter2 < s2.end(); ++iter1, ++iter2) {
    if (*iter1 != *iter2) {
      // No match, need to use our edit
      if (used_edit) {
        return false;
      }
      used_edit = true;
      // Chose to insert, delete, or replace based on string sizes
      if (s1.size() < s2.size()) {
        // Insert in s1
        ++iter2;
      }
      else if (s1.size() > s2.size()) {
        // Delete from  s1
        ++iter1;
      }
      else {
        // Replace in s1
        ++iter1;
        ++iter2;
      }
    }
  }
  return !used_edit || (iter1 == s1.end() && iter2 == s2.end());
}

int main() {
  std::string s1 = "pale", s2 = "ple";
  std::cout << s1 << ", " << s2 << ": " << IsOneAwayRecursive(s1, s2) << std::endl;
  std::cout << s1 << ", " << s2 << ": " << IsOneAway(s1, s2) << std::endl;

  s1 = "pales", s2 = "pale";
  std::cout << s1 << ", " << s2 << ": " << IsOneAwayRecursive(s1, s2) << std::endl;
  std::cout << s1 << ", " << s2 << ": " << IsOneAway(s1, s2) << std::endl;

  s1 = "pale", s2 = "bale";
  std::cout << s1 << ", " << s2 << ": " << IsOneAwayRecursive(s1, s2) << std::endl;
  std::cout << s1 << ", " << s2 << ": " << IsOneAway(s1, s2) << std::endl;

  s1 = "pale", s2 = "bake";
  std::cout << s1 << ", " << s2 << ": " << IsOneAwayRecursive(s1, s2) << std::endl;
  std::cout << s1 << ", " << s2 << ": " << IsOneAway(s1, s2) << std::endl;
}
