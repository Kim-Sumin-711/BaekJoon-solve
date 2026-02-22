#include<iostream>
int main(void) {
	double a, b; std::cin >> a >> b;
	while (!(a == 0 && b == 0)) {
		if (a == 0 || b == 0) std::cout << "AXIS\n";
		else if (a > 0 && b > 0) std::cout << "Q1\n";
		else if (a < 0 && b>0) std::cout << "Q2\n";
		else if (a < 0 && b < 0) std::cout << "Q3\n";
		else std::cout << "Q4\n";
		std::cin >> a >> b;
	}
	std::cout << "AXIS\n";
	return 0;
}