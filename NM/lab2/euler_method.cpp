#include <cmath>
#include <iostream>
#define h  0.1f

float func(float x, float y) { return x*cos(x); }

int main() {
  float a = 0.0f, b = 5.0f;
  float y = 1.0f;
  float x = a;
  do {
    y += func(x, y)*h;
    x += h;
    std::cout << x << "\t" << y << "\n";
  } while (x <= b);
	return 0;
}
