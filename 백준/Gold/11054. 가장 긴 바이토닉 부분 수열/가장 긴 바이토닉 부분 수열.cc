#include<iostream>
#include<vector>
#include<algorithm>

int get_maximum_len_of_Bitonic_sequence(int len, const std::vector<int>& vec) {
	std::vector<int> dp(len, 1);
	//ascending len
	for (int target = 0; target < len; target++) {
		for (int i = 0; i < target; i++) {
			if (vec[target] > vec[i]) {
				dp[target] = std::max(dp[target], dp[i] + 1);
			}
		}
	}
	int max_bitonic_len = 0;
	//어떤 인덱스부터 시작하는 내림차순 수열
	//사실은 좌우바꿔서 보면, 그 인덱스로 끝나는 오름차순(오른쪽->왼쪽) 수열 찾기
	std::vector<int> descending_dp(len, 1);
	for (int begin = len - 1; begin > -1; begin--) {
		for (int end = len-1; end > begin; end--) {
			if (vec[begin] > vec[end]) {
				descending_dp[begin] = std::max(descending_dp[begin], descending_dp[end] + 1);
			}
		}	
	}
	for (int i = 0; i < len; i++) {
		int temp = dp[i] + descending_dp[i] - 1;
		if (max_bitonic_len < temp) max_bitonic_len = temp;
	}
	return max_bitonic_len;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int len;
	std::cin >> len;
	std::vector<int> num_series(len, 0);
	for (auto iter = num_series.begin(); iter != num_series.end(); iter++) {
		std::cin >> *iter;
	}
	std::cout << get_maximum_len_of_Bitonic_sequence(len, num_series);
	return 0;
}