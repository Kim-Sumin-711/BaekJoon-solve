#include<iostream>
int main(void) {
	int n;
	std::cin >> n;
	int ans = 1;
	for (int i = 2; i <= n; i++) ans *= i;
	std::cout << ans;
	return 0;
}