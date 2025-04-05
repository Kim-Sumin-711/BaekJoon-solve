#include<iostream>
#include<vector>
#include<algorithm>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int size; std::cin >> size;
	std::vector<int>num_series(size, 0);
	for (auto iter = num_series.begin(); iter != num_series.end(); iter++) {
		std::cin >> *iter;
	}
	std::vector<int> dp = num_series;
	for (int end = 1; end < size; end++) {
		for (int i = 0; i < end; i++) {
			if (num_series[end] > num_series[i]) {
				dp[end] = std::max(dp[end], dp[i] + num_series[end]);
			}
		}
	}
	std::cout << *std::max_element(dp.begin(), dp.end());
	return 0;
}