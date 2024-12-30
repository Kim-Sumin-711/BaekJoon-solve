#include<iostream>
#include<vector>

int main(void) {
	std::vector<int> dp(11);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	int test;
	std::cin >> test;
	while (test--) {
		int n;
		std::cin >> n;
		std::cout << dp[n] << "\n";
	}

	return 0;
}