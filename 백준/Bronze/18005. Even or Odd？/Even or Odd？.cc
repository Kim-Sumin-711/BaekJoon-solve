#include<iostream>
int main(void) {
	int num;
	std::cin >> num;
	if (num % 4 == 0) std::cout << '2';
	else if (num % 2 == 0) std::cout << '1';
	else std::cout << '0';
	return 0;
}