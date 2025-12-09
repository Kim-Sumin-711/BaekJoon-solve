#include<iostream>
#include<vector>
int INF = 1000000007;

long long sum_big_nums(long long a, long long b) {
	a %= INF; b %= INF;
	return (a + b) % INF;
}

long long multiply_big_nums(long long a, long long b) {
	a %= INF; b %= INF;
	return (a * b) % INF;
}

//get b^(INF-2) --> b^-1 (mod INF)
long long get_modular_inverse_num(long long b, long long floor) {
	if (floor == 0) return 1;
	if (floor % 2 == 0) {
		long long tmp = get_modular_inverse_num(b, floor / 2);
		return multiply_big_nums(tmp, tmp);
	}
	else {
		long long tmp = get_modular_inverse_num(b, floor / 2);
		return multiply_big_nums(multiply_big_nums(tmp, tmp), b);
	}
}

long long get_a_key(long long a, long long b) {
	long long modular_inverse_num = get_modular_inverse_num(b,INF-2);
	return (a * modular_inverse_num) % INF;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int M;
	std::cin >> M;
	std::vector<long long> raional_nums;
	while (M--) {
		long long a, b;
		std::cin >> b >> a;
		long long tmp_key = get_a_key(a, b);
		raional_nums.push_back(tmp_key);
	}
	long long sum = raional_nums[0];
	for (int i = 1; i < raional_nums.size(); i++) {
		sum = sum_big_nums(sum, raional_nums[i]);
	}
	std::cout << sum;
	return 0; 
}