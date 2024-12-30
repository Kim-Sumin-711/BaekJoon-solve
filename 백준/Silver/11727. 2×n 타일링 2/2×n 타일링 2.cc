#include<iostream>
#include<vector>

void set_dp(std::vector<int>& dp) {
	dp[1] = 1;
	dp[2] = 3;
	int div = 10007;
	for (int i = 3; i < 1001; i++) {
		dp[i] = dp[i - 1] + 2*dp[i - 2];
		dp[i] %= div;
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::vector<int>dp(1001);
	set_dp(dp);
	int n;
	std::cin >> n;
	std::cout << dp[n];
	return 0;
}