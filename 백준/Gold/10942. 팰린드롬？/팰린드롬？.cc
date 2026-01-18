#include<iostream>
#include<vector>
//i>j 사용안함.
void set_dp(std::vector<std::vector<bool>>& dp, const std::vector<int>& num_vec) {
	for (int i = 0; i < num_vec.size(); i++) {
		dp[i][i] = true;
	}
	for (int i = 0; i < num_vec.size() - 1; i++) {
		if (num_vec[i] == num_vec[i + 1]) dp[i][i + 1] = true;
	}
	for (int i = num_vec.size() - 2; i > -1; i--) {
		for (int j = i + 1; j < num_vec.size(); j++) {
			if (dp[i + 1][j - 1] && num_vec[i] == num_vec[j]) dp[i][j] = true;
		}
	}
}

void answer_the_question(const std::vector<std::vector<bool>>& dp, int start, int end) {
	//index
	start--; end--;
	if (dp[start][end]) std::cout << 1 << "\n";
	else std::cout << 0 << "\n";
}


int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int num_cnt, question_cnt;
	std::cin >> num_cnt;
	std::vector<int> num_vec(num_cnt);
	for (int i = 0; i < num_cnt; i++) {
		std::cin >> num_vec[i]; 
	}
	std::vector<std::vector<bool>> dp(num_cnt, std::vector<bool>(num_cnt,false));
	set_dp(dp, num_vec);
	std::cin >> question_cnt;
	int start, end;
	while (question_cnt--) {
		std::cin >> start >> end;
		answer_the_question(dp, start, end);
	}
	return 0;
}