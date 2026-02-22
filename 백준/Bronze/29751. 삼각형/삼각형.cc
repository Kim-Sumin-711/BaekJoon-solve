#include<iostream>
int main(void) {
	int a, b; std::cin >> a >> b;
	int ans = a * b;
	if (ans % 2 == 0) std::cout << ans / 2 << ".0";
	else std::cout << ans / 2 << ".5";
	return 0;
}