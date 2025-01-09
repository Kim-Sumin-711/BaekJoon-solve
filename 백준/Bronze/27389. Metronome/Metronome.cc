#include<iostream>
int main(void) {
	double N;
	std::cin >> N;
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << N / 4;
	return 0;
}