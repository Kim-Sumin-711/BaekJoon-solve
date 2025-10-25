#include<iostream>
#include<cmath>

int get_divisor_cnt(int target) {
	if (target == 1) return 1;
	else {
		//one and itself
		int divisor_cnt = 2;
		double sqrt_of_target = std::sqrt(target);
		for (int i = 2; i < (int)sqrt_of_target; i++) {
			if (target % i == 0) divisor_cnt+=2;
		}
		if (sqrt_of_target == (int)sqrt_of_target) divisor_cnt++;
		return divisor_cnt;
	}
}

void sol() {
	int round_cnt, escape_cnt = 0;
	std::cin >> round_cnt;
	int target = 0;
	while (++target <= round_cnt) {
		int divisor_cnt = get_divisor_cnt(target);
		if (divisor_cnt % 2 != 0) escape_cnt++;
	}
	std::cout << escape_cnt << "\n";
}

int main(void) {
	std::cin.tie(0); std::cout.tie(0); std::ios::sync_with_stdio(0);
	int test_case;
	std::cin >> test_case;
	while (test_case--) {
		sol();
	}
	return 0;
}