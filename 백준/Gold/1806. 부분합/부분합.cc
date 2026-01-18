#include<iostream>
#include<vector>
void sol(const std::vector<int>& num_series, int sum_goal) {
	int min_size = 2100000000, prefix_sum = 0;
	int start_index_of_a_vector_that_has_prefix_sum_goal = 0;
	for (int i = 0; i < num_series.size(); i++) {
		prefix_sum += num_series[i];
		if (prefix_sum >= sum_goal) {
			while (prefix_sum >= sum_goal) {
				prefix_sum -= num_series[start_index_of_a_vector_that_has_prefix_sum_goal];
				start_index_of_a_vector_that_has_prefix_sum_goal++;
				//it should be not overflowed.
			}
			if (min_size > i - start_index_of_a_vector_that_has_prefix_sum_goal + 2) {
				min_size = i - start_index_of_a_vector_that_has_prefix_sum_goal + 2;
			}
		}
		
	}
	if (min_size == 2100000000) std::cout << 0;
	else std::cout << min_size;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int series_len, sum_goal;
	std::cin >> series_len >> sum_goal;
	std::vector<int> num_series(series_len);
	for (int& num : num_series) {
		std::cin >> num;
	}
	sol(num_series, sum_goal);

	return 0;
}