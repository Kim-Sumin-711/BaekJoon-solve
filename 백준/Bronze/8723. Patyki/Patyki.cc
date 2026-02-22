#include<iostream>
int main(void) {
	int a, b, c; std::cin >> a >> b >> c;
	if (a == b && b == c) std::cout << 2;
	else {
		if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b) std::cout << 1;
		else std::cout << 0;
	}
	return 0;
}