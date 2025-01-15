#include<iostream>
#include<vector>


void print_max_and_min_score_in_a_game(std::vector<int>& score_board, const int& r_cnt) {
	std::vector < std::pair<int, int> > score_dp(3);
	std::cin >> score_dp[0].first >> score_dp[1].first >> score_dp[2].first;
	score_dp[0].second = score_dp[0].first; score_dp[1].second = score_dp[1].first; score_dp[2].second = score_dp[2].first;
	for (int loop = 1; loop < r_cnt; loop++) {
		std::cin >> score_board[0] >> score_board[1] >> score_board[2];
		int dp_zero_max = score_board[0] + std::max(score_dp[0].first, score_dp[1].first);
		int dp_zero_min = score_board[0] + std::min(score_dp[0].second, score_dp[1].second);
		int dp_one_max = score_board[1] + std::max(std::max(score_dp[0].first, score_dp[1].first), score_dp[2].first);
		int dp_one_min = score_board[1] + std::min(std::min(score_dp[0].second, score_dp[1].second), score_dp[2].second);
		int dp_two_max = score_board[2] + std::max(score_dp[1].first, score_dp[2].first);
		int dp_two_min = score_board[2] + std::min(score_dp[1].second, score_dp[2].second);
		score_dp[0].first = dp_zero_max; score_dp[0].second = dp_zero_min;
		score_dp[1].first = dp_one_max; score_dp[1].second = dp_one_min;
		score_dp[2].first = dp_two_max; score_dp[2].second = dp_two_min;
	}
	std::cout << std::max(std::max(score_dp[0].first, score_dp[1].first), score_dp[2].first);
	std::cout << " ";
	std::cout << std::min(std::min(score_dp[0].second, score_dp[1].second), score_dp[2].second);

}
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int row_cnt;
	std::cin >> row_cnt;
	std::vector<int> score_board(3);
	print_max_and_min_score_in_a_game(score_board, row_cnt);
	return 0;
}