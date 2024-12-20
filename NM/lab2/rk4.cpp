#include <cmath>
#include <iostream>
#define h  0.1f

float func(float x, float y) { return x + y; }

int main() {
  float a = 0.0f, b = 5.0f;
  float y = 1.0f;
  float x = a;
	float k1,k2,k3,k4,k;
  do {
		k1 = h*func(x,y);
		k2 = h*func(x+h/2,y+k1/2);
		k3 = h*func(x+h/2,y+k2/2);
		k4 = h*func(x+h,y+k3);
		k = (k1+2.0f*(k2+k3)+k4)/6.0f; 
    y += k;
    x += h;
    std::cout << x << "," << y << "\n";
  } while (x <= b);
	return 0;
}
