#include <bits/std_thread.h>
#include <iostream>
#include <string>

int value(char op) {
  switch (op) {
  case '+':
    return 0;

  case '-':
    return 0;

  case '*':
    return 1;

  case '/':
    return 1;

  case '(':
    return -1;

  default:
    return -2;
  }
}

int main() {
  std::string in_expression;
  std::string post_expression;
  std::string stack;

  std::cout << "enter expression:";
  std::cin >> in_expression;
	int i=0;

  while (!in_expression.empty()) {
  
    char c = in_expression.front();
    if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')') {
      post_expression.push_back(c);
    } else if (c == '(') {
      stack.push_back(c);
    } else if (c == ')') {
      char to_add = *--stack.end();
      while (to_add != '(') {
        post_expression.push_back(to_add);
        stack.pop_back();
        to_add = *--stack.end();
      }
			stack.pop_back();
    } else {
      if (stack.empty()) {
        stack.push_back(c);
      } else if (value(c) > value(*--stack.end())) {
        stack.push_back(c);
      } else {
        do {
          post_expression.push_back(*--stack.end());
          stack.pop_back();
        } while (value(c) < value(*--stack.end()));
				stack.push_back(c);
      }
    }
		in_expression.erase(0,1);
  }

	while(!stack.empty())
	{
		char to_add = *--stack.end();
		post_expression.push_back(to_add);
		stack.pop_back();
	}
	std::cout << "the expression is : " << post_expression << "\n";
	return 0;
}
