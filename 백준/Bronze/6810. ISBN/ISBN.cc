#include<iostream>
int main(void) {
	int a, ans = 91;
	std::cin >> a;
	ans += a;
	std::cin >> a;
	ans += a*3;
	std::cin >> a;
	ans += a;
	std::cout << "The 1-3-sum is " << ans;
	return 0;
}