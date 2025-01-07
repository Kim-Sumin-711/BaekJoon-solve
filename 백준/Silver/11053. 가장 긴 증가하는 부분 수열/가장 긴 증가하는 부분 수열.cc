#include<iostream>
#include<vector>
#include<algorithm>

void set_vec(std::vector<int>& vec) {
	for (int& elem : vec)
		std::cin >> elem;
}

void get_long_vec_size_to_target_point(const std::vector<int>& num_vec, std::vector<int>& dp, const int& target_point) {
	int max_size = 1;
	for (int i = 1; target_point >= i; i++) {
		if (num_vec[target_point - i] < num_vec[target_point])
			if (max_size < dp[target_point - i] + 1)
				max_size = dp[target_point - i] + 1;
	}
	dp[target_point] = max_size;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int size;
	std::cin >> size;
	std::vector<int> num_vec(size),dp(size);
	set_vec(num_vec);
	dp[0] = 1;
	for (int target_index = 1; target_index < size; target_index++) {
		get_long_vec_size_to_target_point(num_vec, dp, target_index);
	}
	std::cout << *std::max_element(dp.begin(), dp.end());
	return 0;
}