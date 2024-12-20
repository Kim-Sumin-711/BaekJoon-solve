#include<iostream>
int main(void) {
	int res = 0;
	for (int i = 0; i < 5; i++) {
		int tmp;
		std::cin >> tmp;
		res += tmp * tmp;
	}
	std::cout << res % 10;
	return 0;
}