#include<iostream>
#include<vector>
#include<algorithm>
void set_cost_vec(std::vector<std::vector<short>>& cost_vec) {
	for (std::vector<short>& house : cost_vec) {
		for (short& cost : house) {
			std::cin >> cost;
		}
	}
}

int sol(const std::vector<std::vector<short>>& cost_vec, int house_cnt, int zero_house_color) {
	//r == 0; g == 1; b == 2; nothing == -1;
	std::vector<std::vector<int>> cost_dp(house_cnt,std::vector<int>(3,2100000000));
	cost_dp[0][zero_house_color] = cost_vec[0][zero_house_color];

	for (int c = 0; c < 3; c++) {
		if (cost_dp[0][c] == 2100000000) {
			cost_dp[1][c] = cost_vec[1][c] + cost_vec[0][zero_house_color];
		}
	}
	if (house_cnt == 2) {
		return *std::min_element(cost_dp[1].begin(), cost_dp[1].end());
	}
	else {
		int new_cost = 0, target_home_num = 0;
		while (++target_home_num != house_cnt-2)
		for (int c = 0; c < 3; c++) {
			if (cost_dp[target_home_num][c] != 2100000000) {
				for (int other_c = 0; other_c < 3; other_c++) {
					if (c!= other_c && cost_dp[target_home_num + 1][other_c] > cost_dp[target_home_num][c] + cost_vec[target_home_num + 1][other_c]) {
						cost_dp[target_home_num + 1][other_c] = cost_dp[target_home_num][c] + cost_vec[target_home_num + 1][other_c];
					}
				}
			}
		}
		for (int c = 0; c < 3; c++) {
			if (cost_dp[house_cnt-2][c] != 2100000000) {
				for (int other_c = 0; other_c < 3; other_c++) {
					if (c != other_c && other_c != zero_house_color) {
						if (cost_dp[house_cnt - 1][other_c] > cost_dp[house_cnt - 2][c] + cost_vec[house_cnt - 1][other_c])
							cost_dp[house_cnt - 1][other_c] = cost_dp[house_cnt - 2][c] + cost_vec[house_cnt - 1][other_c];
					}
				}
			}
		}
		return *std::min_element(cost_dp[house_cnt - 1].begin(), cost_dp[house_cnt - 1].end());
	}

}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int house_cnt; std::cin >> house_cnt;
	std::vector<std::vector<short>> cost_vec(house_cnt, std::vector<short>(3));
	set_cost_vec(cost_vec);
	int ans = 2100000000, temp_ans = 0;;
	for (int c = 0; c < 3; c++) {
		temp_ans = sol(cost_vec, house_cnt, c);
		if (ans > temp_ans) {
			ans = temp_ans;
		}
	}
	std::cout << ans;
	return 0;
}