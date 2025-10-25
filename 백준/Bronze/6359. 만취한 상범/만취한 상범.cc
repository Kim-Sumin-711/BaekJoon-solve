#include<iostream>
#include<cmath>
int main(void) {
	//제곱수 --> 약수의 개수 홀수 --> open, can escape
	//1~round_cnt 에서의 제곱수 개수.
	//(int)std::sqrt(round_cnt);
	std::cin.tie(0); std::cout.tie(0); std::ios::sync_with_stdio(0);
	int test_case;
	std::cin >> test_case;
	while (test_case--) {
		int round_cnt;
		std::cin >> round_cnt;
		std::cout << (int)std::sqrt(round_cnt) << "\n";
	}
	return 0;
}