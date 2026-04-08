#include<iostream>
#include<vector>
#include<cmath>
void set_pattern_vec(std::vector<int>& pattern_vec) {
	int note = 67;
	std::cin >> note;
	while (note != 0) {
		pattern_vec.push_back(note);
		std::cin >> note;
	}
}

int get_me_minimal_cost(const std::vector<int>& pattern_vec) {
	std::vector<std::vector<std::vector<int>>>
		dp(pattern_vec.size(), std::vector<std::vector<int>>(5, std::vector<int>(5, 2100000000)));
	dp[0][pattern_vec[0]][0] = 2; dp[0][0][pattern_vec[0]] = 2;
	for (int i = 1; i < pattern_vec.size(); i++) {
		int note = pattern_vec[i];
		//think about [now_note][somewhere not now_note]
		for (int right_foot = 0; right_foot < 5; right_foot++) {
			if (pattern_vec[i] != right_foot) {
				for (int left_foot = 0; left_foot < 5; left_foot++) {
					if (left_foot == right_foot) continue;
					if (dp[i - 1][left_foot][right_foot] != 2100000000) {
						if (left_foot == 0) {
							int now_cost = dp[i - 1][left_foot][right_foot] + 2;
							if (dp[i][pattern_vec[i]][right_foot] > now_cost) {
								dp[i][pattern_vec[i]][right_foot] = now_cost;
							}
						}
						else if (std::abs(left_foot - pattern_vec[i]) == 2) {
							int now_cost = dp[i - 1][left_foot][right_foot] + 4;
							if (dp[i][pattern_vec[i]][right_foot] > now_cost) {
								dp[i][pattern_vec[i]][right_foot] = now_cost;
							}
						}
						else if (std::abs(left_foot - pattern_vec[i]) == 1 || std::abs(left_foot - pattern_vec[i]) == 3) {
							int now_cost = dp[i - 1][left_foot][right_foot] + 3;
							if (dp[i][pattern_vec[i]][right_foot] > now_cost) {
								dp[i][pattern_vec[i]][right_foot] = now_cost;
							}
						}
						else {
							int now_cost = dp[i - 1][left_foot][right_foot] + 1;
							if (dp[i][pattern_vec[i]][right_foot] > now_cost) {
								dp[i][pattern_vec[i]][right_foot] = now_cost;
							}
						}
					}

				}
			}
		}
		for (int left_foot = 0; left_foot < 5; left_foot++) {
			if (pattern_vec[i] != left_foot) {
				for (int right_foot = 0; right_foot < 5; right_foot++) {
					if (left_foot == right_foot) continue;
					if (dp[i - 1][left_foot][right_foot] != 2100000000) {
						if (right_foot == 0) {
							int now_cost = dp[i - 1][left_foot][right_foot] + 2;
							if (dp[i][left_foot][pattern_vec[i]] > now_cost) {
								dp[i][left_foot][pattern_vec[i]] = now_cost;
							}
						}
						else if (std::abs(right_foot - pattern_vec[i]) == 2) {
							int now_cost = dp[i - 1][left_foot][right_foot] + 4;
							if (dp[i][left_foot][pattern_vec[i]] > now_cost) {
								dp[i][left_foot][pattern_vec[i]] = now_cost;
							}
						}
						else if(std::abs(right_foot-pattern_vec[i])==1 || std::abs(right_foot - pattern_vec[i]) == 3) {
							int now_cost = dp[i - 1][left_foot][right_foot] + 3;
							if (dp[i][left_foot][pattern_vec[i]] > now_cost) {
								dp[i][left_foot][pattern_vec[i]] = now_cost;
							}
						}
						else {
							int now_cost = dp[i - 1][left_foot][right_foot] + 1;
							if (dp[i][left_foot][pattern_vec[i]] > now_cost) {
								dp[i][left_foot][pattern_vec[i]] = now_cost;
							}
						}
					}

				}
			}
		}
	}
	int ans = 2100000000;
	for (int left_foot = 0; left_foot < 5; left_foot++) {
		if (left_foot != pattern_vec[pattern_vec.size() - 1]) {
			if (ans > dp[dp.size() - 1][left_foot][pattern_vec[pattern_vec.size() - 1]])
				ans = dp[dp.size() - 1][left_foot][pattern_vec[pattern_vec.size() - 1]];
		}
	}
	for (int right_foot = 0; right_foot < 5; right_foot++) {
		if (right_foot != pattern_vec[pattern_vec.size() - 1]) {
			if (ans > dp[dp.size() - 1][pattern_vec[pattern_vec.size()-1]][right_foot])
				ans = dp[dp.size() - 1][pattern_vec[pattern_vec.size()-1]][right_foot];
		}
	}
	return ans;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::vector<int> pattern_vec;
	set_pattern_vec(pattern_vec);
	int ans = get_me_minimal_cost(pattern_vec);
	std::cout << ans;
	return 0;
}