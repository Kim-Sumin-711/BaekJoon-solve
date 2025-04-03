#include<iostream>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		int N, C;
		std::cin >> N >> C;
		if (N % C==0) {
			std::cout << N / C << "\n";
		}
		else std::cout << N / C + 1 << "\n";
	}

	return 0;
}