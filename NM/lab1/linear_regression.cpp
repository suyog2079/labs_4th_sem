/**
 * @file
 * @brief for linear regression
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

float sum(std::vector<float> a, int size) {
  float sum;
  for (int i = 0; i < size; i++) {
    sum += a[i];
  }
  return sum;
}

int main() {
  float a;
  float b;
  std::vector<float> x;
  std::vector<float> y;
  std::vector<float> xy;
  std::vector<float> xx;

  int n;
  std::cout << "Enter the number of data" << std::endl;
  std::cin >> n;
  x.resize(n + 1);
  y.resize(n + 1);
  xy.resize(n + 1);
  xx.resize(n + 1);

  for (int i = 0; i < n; i++) {
    std::cout << "x: ";
    std::cin >> x[i];

    std::cout << "y: ";
    std::cin >> y[i];
  }

  for (int i = 0; i < n; i++) {
    xy[i] = x[i] * y[i];
  }
  for (int i = 0; i < n; i++) {
    xx[i] = x[i] * x[i];
  }

  float sumx = sum(x, n);
  float sumxx = sum(xx, n);
  float sumy = sum(y, n);
  float sumxy = sum(xy, n);

  float denom = n * sumxx - sumx * sumx;
  if (denom == 0) {
    std::cout << "cannot perform liner regression" << std::endl;
    return 0;
  }
  a = (sumy * sumxx - sumx * sumxy) / denom;
  b = (n * sumxy - sumx * sumy) / denom;

	std::cout << "the equation is : y = " << a << " + " << b << "x" << std::endl; 

  return 0;
}
