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
#define tolerance 0.000001f

/**
 * @brief this function takes x and returns f(x)
 *
 * @param x input of the function
 * @return output of the function
 */
float func(float x) {
  // float f_of_x = 0.0f;
  // for (int i = 0; i <= degree; i++) {
  //   f_of_x += base[i] * pow(x, i);
  // }
  // return f_of_x;
  float f_of_x = pow(x, -3) + sin(x);
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
  // recursion_counter++;
  // float c = (a + b) / 2.0f;
  // if (recursion_counter > recursion_depth) {
  //   throw 1;
  // }
  // if (fabs(c - prev_C) < tolerance) {
  //   return c;
  // }
  // prev_C = c;
  // if (func(a) * func(c) < 0) {
  //   return solve(a, c);
  // } else {
  //   return solve(c, b);
  // }
  float c;
  float recursion_counter = 0;
  float recursion_depth = 2 * ((fabs(a - b) - log(fabs(tolerance))) / log(2));

  do {
    recursion_counter++;
    if (recursion_counter >= recursion_depth) {
      throw -1;
    }
    c = (a + b) / 2.0f;
    if (func(a) * func(c) < 0) {
      b = c;
    } else {
      a = c;
    }
  } while (fabs(a - b) >= tolerance);
  return c;
}

int main() {
  // std::cout << "enter the degree of equation" << std::endl;
  // std::cin >> degree;
  // base.resize(degree + 1);
  //
  // for (int i = 0; i <= degree; i++) {
  //   std::cout << "enter " << i << "th base" << std::endl;
  //   std::cin >> base[i];
  // }
  float a;
  float b;
  std::cout << "enter the interval: ";
  std::cin >> a >> b;
  if (func(a) * func(b) < 0) {
    try {
      float solution = solve(a, b);
      if (fabs(func(solution)) > 1000 * tolerance) {
        std::cerr << "the function is discontinuous\n";
      } else
        std::cout << "the root is " << solve(a, b) << std::endl;
    } catch (...) {
      std::cerr << "the function is discontinuous\n";
    }
  } else {
    std::cout << "probably no root in given limits\n";
  }
  // std::cout << recursion_counter << std::endl;
  return 0;
}
