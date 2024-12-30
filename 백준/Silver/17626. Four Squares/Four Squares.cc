#include<iostream>
#include<vector>

void set_dp(std::vector<int>& dp) {
	for (int i = 1; i < 224; i++)
		dp[i * i] = 1;
	int near_down_sq = 0;
	for (int i = 1; i < 50001; i++) {
		if (dp[i] == 1)
			near_down_sq++;
		else {
			int mini = dp[i-near_down_sq*near_down_sq]+1;
			for (int sq = near_down_sq-1; sq >= 1; sq--) {
				if (mini > dp[i - sq * sq] + 1) {
					mini = dp[i - sq * sq] + 1;
				}
			}
			dp[i] = mini;
		}
	}
}

int main(void) {
	std::vector<int>dp(50001);
	set_dp(dp);
	int target;
	std::cin >> target;
	std::cout << dp[target];
	return 0;
}