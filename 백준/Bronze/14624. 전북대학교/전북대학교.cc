#include<iostream>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int N;
	std::cin >> N;
	if (N % 2 == 0) {
		std::cout << "I LOVE CBNU";
	}
	else {
		for (int i = 0; i < N; i++) {
			std::cout << '*';
		}
		std::cout << "\n";
		int oper_cnt = 0;
		while (oper_cnt != N / 2 + 1) {
			for (int i = 0; i < N; i++) {
				if (i == N / 2 + oper_cnt || i == N / 2 - oper_cnt)
					std::cout << '*';
				else if (i > N / 2 + oper_cnt)
					break;
				else
					std::cout << ' ';
			}
			std::cout << "\n";
			oper_cnt++;
		}
		
	}
	return 0;
}