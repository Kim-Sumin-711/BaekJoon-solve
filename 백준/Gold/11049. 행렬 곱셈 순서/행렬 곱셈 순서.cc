#include<iostream>
#include<vector>

void set_matrix_vec(std::vector<std::pair<int, int>>& matrix_vec) {
	int r, c;
	for (int i = 0; i < matrix_vec.size(); i++) {
		std::cin >> r >> c;
		matrix_vec[i] = { r,c };
	}
}

long long get_minimal_calc_cnt_for_given_section(const std::vector<std::pair<int, int>>& matrix_vec, int start, int end, std::vector<std::vector<long long>>& dp) {
	if (end - start == 0) return 0;
	else if (end - start == 1) return matrix_vec[start].first * matrix_vec[start].second * matrix_vec[end].second;
	else {
		long long ans = 21000000000;
		for (int i = start; i < end; i++) {
			long long front_part_ans = 0, post_part_ans = 0;
			if (dp[start][i] != -1) front_part_ans = dp[start][i];
			else {
				dp[start][i] = get_minimal_calc_cnt_for_given_section(matrix_vec, start, i, dp);
				front_part_ans = dp[start][i];
			}

			if (dp[i + 1][end] != -1) post_part_ans = dp[i + 1][end];
			else {
				dp[i+1][end] = get_minimal_calc_cnt_for_given_section(matrix_vec, i + 1, end, dp);
				post_part_ans = dp[i + 1][end];
			}
			long long temp_ans = matrix_vec[start].first * matrix_vec[i].second * matrix_vec[end].second;
			temp_ans += front_part_ans;
			temp_ans += post_part_ans;
			if (temp_ans < ans) ans = temp_ans;
		}
		dp[start][end] = ans;
		return ans;
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int N; std::cin >> N;
	std::vector<std::pair<int, int>> matrix_vec(N);
	set_matrix_vec(matrix_vec);
	std::vector<std::vector<long long>> minimal_calc_cnt_for_each_section(N, std::vector<long long>(N, -1));
	long long ans = get_minimal_calc_cnt_for_given_section(matrix_vec, 0, N-1, minimal_calc_cnt_for_each_section);
	std::cout << ans;
	return 0;
}