#include<iostream>
int main(void) {
	int test;
	std::cin >> test;
	while (test--) {
		int x, y;
		std::cin >> x >> y;
		if (x >= y)
			std::cout << "MMM BRAINS\n";
		else
			std::cout << "NO BRAINS\n";
	}
	return 0;
}
