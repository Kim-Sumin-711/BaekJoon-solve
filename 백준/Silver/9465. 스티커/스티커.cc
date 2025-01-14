#include<iostream>
#include<vector>
using Sticker = std::vector<std::vector<short>>;
using Sticker_row = std::vector<short>;
using DP_type = std::vector<std::vector<int>>;
using DP_row_type = std::vector<int>;

void set_sticker_vec(Sticker& sticker_vec,const int& col_cnt) {
	for (int c = 0; c < col_cnt; c++)
		std::cin >> sticker_vec[0][c];
	for (int c = 0; c < col_cnt; c++)
		std::cin >> sticker_vec[1][c];

}

void sol(const Sticker& sticker_vec, const int& col_cnt) {
	DP_type dp(2, DP_row_type(col_cnt));
	dp[0][0] = sticker_vec[0][0];
	dp[1][0] = sticker_vec[1][0];
	if (col_cnt == 2) {
		dp[0][1] = sticker_vec[1][0] + sticker_vec[0][1];
		dp[1][1] = sticker_vec[1][1] + sticker_vec[0][0];
		std::cout << std::max(dp[0][1], dp[1][1]) << "\n";
	}
	else if (col_cnt > 2) {
		dp[0][1] = sticker_vec[1][0] + sticker_vec[0][1];
		dp[1][1] = sticker_vec[1][1] + sticker_vec[0][0];
		for (int c = 2; c < col_cnt; c++) {
			dp[0][c] = sticker_vec[0][c] + std::max(std::max(dp[1][c - 1], dp[0][c - 2]), dp[1][c - 2]);
			dp[1][c] = sticker_vec[1][c] + std::max(std::max(dp[0][c - 1], dp[0][c - 2]), dp[1][c - 2]);
		}
		std::cout << std::max(std::max(dp[0][col_cnt - 1], dp[1][col_cnt-1]), std::max(dp[0][col_cnt - 2], dp[1][col_cnt - 2])) << "\n";
	}
	else
		std::cout << std::max(dp[0][0], dp[1][0]) << "\n";
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int test_case;
	std::cin >> test_case;
	while (test_case--) {
		int col_cnt;
		std::cin >> col_cnt;
		Sticker sticker_vec(2,Sticker_row(col_cnt,0));
		set_sticker_vec(sticker_vec, col_cnt);
		sol(sticker_vec, col_cnt);
	}
	return 0;
}