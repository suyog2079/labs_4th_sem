#include <iostream>
#include <iterator>
#include <ostream>

int main()
{
	int max = 10;
	int stack[10];
	int top=-1;
	int choice;
	bool cont;

	do{
		std::cout << "enter choice:\n" << "0: push \n 1: pop";
		std::cin >> choice;

		switch (choice) {
			case 0:
				if(top == max)
				{
					std::cout << "stack already full\n";
					break;
				}
				top++;
				std::cout << "enter int to push:";
				std::cin >> stack[top];

				break;

			case 1:
				if(top<0)
				{
					std::cout << "stack empty\n";
					break;
				}
				std::cout << stack[top] << std::endl;
				top--;

				break;

			default:
				std::cout << "invalid input\n";
				break;
		}
		std::cout << "wanna continue(0/1)?: ";
		std::cin >> cont;
	}while (cont);
	return 0;
}