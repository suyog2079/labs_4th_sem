#include <iostream>
#include <string>

int main()
{
	std::string str;
	int c=0;

	std::cin >> str;
	while (!str.empty()) {

		if(str.front() == '(') c++;
		else if (str.front() == ')') c--;
		str.erase(0,1);
	}
	if(c==0) std::cout << "valid";
	else std::cout << "invalid";
}

