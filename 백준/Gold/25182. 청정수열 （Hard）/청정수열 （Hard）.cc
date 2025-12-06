#include<iostream>
int INF = 1000000007;

void sum_big_ver(long long& a, long long b) {
	a %= INF;
	b %= INF;
	long long ans = (a + b) % INF;
	a = ans;
}

long long multiply_big_ver(long long a, long long b) {
	a %= INF;
	b %= INF;
	long long ans = (a * b) % INF;
	return ans;
}

long long get_maximum_of_score(int N) {
	long long ans = 0;
	long long sum_step_by_step = 0;
	for (int elem = 1; elem < N + 1; elem++) {
		long long elem_two_times = 2 * elem;
		sum_big_ver(sum_step_by_step, elem_two_times);
		sum_big_ver(ans, multiply_big_ver(sum_step_by_step, elem));
	}
	return ans;
}

long long get_count_of_max_series(int N) {
	long long ans = 1;
	for (long long mul = 2; mul < N + 1; mul++) {
		long long square_of_mul = multiply_big_ver(mul, mul);
		ans = multiply_big_ver(ans, square_of_mul);
	}
	return ans;
}

void print_ans(int N) {
	long long max_score = get_maximum_of_score(N);
	long long count_of_max_series = get_count_of_max_series(N);
	std::cout << max_score << ' ' << count_of_max_series;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int N;
	std::cin >> N;
	print_ans(N);
	return 0;
}