#include<iostream>
int main(void) {
	int a, b; std::cin >> a >> b;
	int c, n; std::cin >> c >> n;
	if (a * n + b > c * n) std::cout << 0;
	else if (a > c) std::cout << 0;
	else std::cout << 1;
	return 0;
}