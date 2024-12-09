#include <algorithm>
#include <cmath>
#include <codecvt>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
  std::string expression;
  int b, c, d;
  std::cout << "enter expression: ";
  std::cin >> expression;
  std::stack<int> a;

  while (!expression.empty()) {
    char first = expression.front();
    if (first != '+' && first != '-' && first != '*' && first != '/') {
      a.push(first - '0');
    } else {
      b = a.top();
      a.pop();
      c = a.top();
      switch (first) {

      case '+':
        d = b + c;
        break;

      case '-':
        d = b - c;
        break;

      case '*':
        d = b * c;
        break;

      case '/':
        d = b / c;
        break;
      }
    }
    a.push(d);
    expression.erase(0, 1);
  }
  std::cout << "the result is: " << a.top() << "\n";
  return 0;
}
