#include <iostream>

using namespace std;

template<int n, int m>
void ZeroRowsCols(int (&mat)[n][m]) {
  // Mark first row and column entries to zero
  // Have to mark row 0 separately, since mat[0][0]
  // marks column 0.
  bool zero_row0 = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 0) {
        if (i > 0) {
          mat[i][0] = 0;
        }
        else {
          zero_row0 = true;
        }
        mat[0][j] = 0;
      } 
    }
  }
  // Zero rows after row zero
  for (int i = 1; i < n; ++i) {
    if (mat[i][0] == 0) {
      for (int j = 0; j < m; ++j) {
        mat[i][j] = 0;
      }
    }
  }
  // Zero columns
  for (int j = 0; j < m; ++j) {
    if (mat[0][j] == 0) {
      for (int i = 0; i < n; ++i) {
        mat[i][j] = 0;
      }
    }
  }
  // Zero row0
  if (zero_row0) {
    for (int j = 0; j < m; ++j) {
      mat[0][j] = 0;
    }
  }
}

template<int n, int m>
void Print(int (&mat)[n][m]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int mat[6][7] {
    { 1, 2, 3, 0, 5, 6, 7 },
    { 1, 2, 3, 4, 0, 6, 7 },
    { 1, 0, 3, 4, 5, 6, 7 },
    { 1, 2, 3, 4, 5, 6, 7 },
    { 1, 2, 3, 4, 5, 6, 7 },
    { 1, 2, 3, 4, 5, 0, 7 }
  };

  ZeroRowsCols(mat);
  Print(mat);
}
