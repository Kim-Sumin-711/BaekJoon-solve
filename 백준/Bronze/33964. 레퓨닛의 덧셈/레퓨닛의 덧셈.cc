#include<iostream>
void sol(int a, int b) {
	int print_1 = a - b;
	while (print_1--) {
		std::cout << 1;
	}
	while (b--) {
		std::cout << 2;
	}
}
int main(void) {
	int a, b;
	std::cin >> a >> b;
	if (a > b) sol(a, b);
	else sol(b, a);
	return 0;
}