#include<iostream>
int main(void) {
	std::ios::sync_with_stdio(0); std::cout.tie(0); std::cin.tie(0);
	int test;
	std::cin >> test;
	while (test--) {
		int d, n, s, p;
		std::cin >> d >> n >> s >> p;
		if (d + n * p > n * s)
			std::cout << "do not parallelize\n";
		else if (d + n * p == n * s)
			std::cout << "does not matter\n";
		else
			std::cout << "parallelize\n";
	}
	return 0;
}