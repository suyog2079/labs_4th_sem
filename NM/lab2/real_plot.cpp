#include <cmath>
#include <iostream>

float func(float x) { return 2 * exp(x)-x - 1; }

int main() {
	for (float i=0; i<=5.0f; i+=0.001f) {
		std::cout << i << "," << func(i) << "\n";
	}
	return 0;
}
