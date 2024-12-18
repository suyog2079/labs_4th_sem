#include <iostream>
#include <stack>
#include <string>

int main() {
  std::string expression;
  std::cout << "enter expression: ";
  std::cin >> expression;
  std::stack<int> stk;

  while (!expression.empty()) {
    char first = expression.front();
    expression.erase(0, 1);

    if (isalnum(first)) {
      int number = first - '0';
      stk.push(number);
    } else {
      int a = stk.top();
      stk.pop();
      int b = stk.top();
      stk.pop();
      switch (first) {
      case '+':
        stk.push(a + b);
        break;
      case '-':
        stk.push(a - b);
        break;
      case '*':
        stk.push(a * b);
        break;
      case '/':
        stk.push(a / b);
        break;
      default:
        break;
      }
    }
  }
  int result = stk.top();
  std::cout << "result: " << result << "\n";
  return 0;
}
