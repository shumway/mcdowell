#include <array>
#include <iostream>
#include <vector>


class Tower {
public:
  Tower(int n) {
    for (int i = n; i > 0; --i) stack[0].push_back(i);
  }

  bool Move(int to, int from) {
    if (stack[from].empty()) return false;
    int val = stack[from].back();
    if (!stack[to].empty() && stack[to].back() <= val) return false;
    stack[from].resize(stack[from].size() - 1);
    stack[to].push_back(val);
    return true;
  }

  std::array<std::vector<int>, 3> stack;
};

void Print(const Tower& t) {
  std::cout << "( ";
  for (int v: t.stack[0]) std::cout << v;
  std::cout << " | ";
  for (int v: t.stack[1]) std::cout << v;
  std::cout << " | ";
  for (int v: t.stack[2]) std::cout << v;
  std::cout << " )\n";
}

void Move(Tower& tower, int to, int from, int num) {
  if (num <= 0) return; 
  int other = 3 - to - from; // to + from + other = 3
  Move(tower, other, from, num - 1);
  tower.Move(to, from);
  Print(tower);
  Move(tower, to, other, num - 1);
}

void Solve(Tower& t) {
  Move(t, 2, 0, t.stack[0].size());
}


int main() {
  for (int i = 0; i < 5; ++i) {
    std::cout << "Tower with " << i << (i != 1 ? " rings" : " ring");
    std::cout << " (" << ((1 << i) - 1) << (i != 1 ? " steps" : " step") << ")\n";
    Tower tower(i);
    Print(tower);
    Solve(tower);
  }
}

