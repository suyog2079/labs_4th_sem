/**
 * @file bisection_method.cpp
 * @brief this is my implementation of bisection method. This code doesnot work
 * for function with roots higher than 10.
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

std::vector<float> base;
int degree;
float prev_C = 0.0f;
#define tolerance 0.0001f
#define recursion_depth 15
int recursion_counter = 0;

/**
 * @brief this function takes x and returns f(x)
 *
 * @param x input of the function
 * @return output of the function
 */
float answer(float x) {
  float f_of_x = 0.0f;
  for (int i = 0; i <= degree; i++) {
    f_of_x += base[i] * pow(x, i);
  }
  return f_of_x;
}

/**
 * @brief recursive function to actually calculate the roots by bisecting the
 * two inputs
 *
 * @param a lower input
 * @param b higher input
 * @return the root of the given equation
 */
float solve(float a, float b) {
  recursion_counter++;
  float c = (a + b) / 2.0f;
  // if (recursion_counter > recursion_depth) {
  // 	return c;
  // }
  if (fabs(c - prev_C) < tolerance) {
    return c;
  }
  prev_C = c;
  if (answer(a) * answer(c) < 0) {
    return solve(a, c);
  } else {
    return solve(c, b);
  }
  return 0.0f;
}

int main() {
  std::cout << "enter the degree of equation" << std::endl;
  std::cin >> degree;
  base.resize(degree + 1);

  for (int i = 0; i <= degree; i++) {
    std::cout << "enter " << i << "th base" << std::endl;
    std::cin >> base[i];
  }
  float a = 0.0f;
  float b = 0.0f;
  std::cout << "the root is " << solve(0.0f, 10.0f) << std::endl;
  ;
  std::cout << recursion_counter << std::endl;
  return 0;
}
