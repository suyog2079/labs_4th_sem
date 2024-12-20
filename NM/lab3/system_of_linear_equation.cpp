#include <iostream>
int main() {
  int n;
  std::cout << "enter number of equations: ";
  std::cin >> n;
  float a[n][n + 1];
  std::cout << "enter elements of matrix: \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n + 1; j++) {
      std::cout << "M[" << i << "][" << j << "]: ";
      std::cin >> a[i][j];
      std::cout << "\n";
    }
  }
  std::cout << "=========================================================\n";
  std::cout << "the matrix: \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n + 1; j++) {
      std::cout << a[i][j] << "\t";
    }
    std::cout << "\n";
  }
  for (int j = 0; j < n; j++) {
    if (a[j][j] == 0.0f) {
      std::cout << "error\n";
      return 0;
    }
    for (int i = 0; i < n; i++) {
      if (i == j)
        continue;
      float ratio = a[i][j] / a[j][j];
      for (int k = 0; k < n + 1; k++) {
        a[i][k] = a[i][k] - ratio * a[j][k];
      }
    }
  }
  std::cout << "the diagonal matrix: \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n + 1; j++) {
      std::cout << a[i][j] << "\t";
    }
    std::cout << "\n";
  }
  std::cout << "the answers are: \n";
  for (int i = 0; i < n; i++) {
    std::cout << a[i][n] / a[i][i] << "\n";
  }
  return 0;
}
