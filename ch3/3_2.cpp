#include <iostream>
#include <vector>
#include <string>

class PackedBinaryTree {
public:
  void Set(const std::vector<int>& input) {
    data.resize(input.size(), 0);
    // Fill with inorder traversal
    auto index = 0;
    Fill(0, index, input);
  }

  int Root() const { return data.empty() ? -1 : 0; }

  int LeftChild(int i) const {
    size_t index = 2 * i + 1;
    return (index < data.size()) ? index : -1;
  }

  int RightChild(int i) const {
    size_t index = 2 * i + 2;
    return (index < data.size()) ? index : -1;
  }

  int Parent(int i) const {
    return (i > 0) ? (i - 1) / 2 : -1;
  }

  std::vector<int> data;

  private:

  void Fill(int node, int& index, const std::vector<int>& input) {
    if (node == -1 || index >= int(input.size())) return;
    Fill(LeftChild(node), index, input);
    if (index >= int(input.size())) return;
    data[node] = input[index++];
    if (index >= int(input.size())) return;
    Fill(RightChild(node), index, input);
  }
};

void Print(const PackedBinaryTree& tree, int root, int indent) {
  if (root < 0 || root >= tree.data.size()) return;
  Print(tree, tree.LeftChild(root), indent + 2);
  std::cout << std::string(indent, ' ') << tree.data[root] << "\n";
  Print(tree, tree.RightChild(root), indent + 2);
}

int main() {
  PackedBinaryTree tree;
  std::cout << "Tree with 8 elements:\n";
  tree.Set(std::vector<int> { 1, 2, 3, 4, 5, 6, 7, 8 });
  Print(tree, 0, 0);
  std::cout << "Tree with no elements:\n";
  tree.Set(std::vector<int> { });
  Print(tree, 0, 0);
  std::cout << "Tree with 15 elements:\n";
  tree.Set(std::vector<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 });
  Print(tree, 0, 0);
  std::cout << "Tree with 5 elements:\n";
  tree.Set(std::vector<int> { 3, 5, 7, 11, 13 });
  Print(tree, 0, 0);
}
