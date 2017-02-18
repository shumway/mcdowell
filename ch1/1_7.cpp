#include <iostream>

using namespace std;


template<int n>
void Rotate(int (&mat)[n][n]) {
  for (int i = 0; i < n / 2; ++i) {
     for (int j = i; j < n - 1; ++j) {
        int temp = mat[i][j];
        mat[i][j] = mat[j][n - 1 - i];
        mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
        mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
        mat[n - 1 - j][i] = temp;
     }
  }
}

template<int n>
void Print(int (&mat)[n][n]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {
  int mat5[5][5] {
    {  1,  2,  3,  4,  5 },
    {  6,  7,  8,  9, 10 },
    { 11, 12, 13, 14, 15 },
    { 16, 17, 18, 19, 20 },
    { 20, 21, 23, 24, 25 }
  };

  Rotate(mat5);
  cout << "5x5 Matrix rotated 90 degrees CCW" << endl;
  Print(mat5);

  int mat4[4][4] {
    {  1,  2,  3,  4 },
    {  5,  6,  7,  8 },
    {  9, 10, 11, 12 },
    { 13, 14, 15, 16 }
  };

  Rotate(mat4);
  cout << "\n4x4 Matrix rotated 90 degrees CCW" << endl;
  Print(mat4);
}

