#include<iostream>
#include<vector>
bool is_it_Palindrome(const std::vector<int>& num_vec, int start, int end) {
	bool Palindrome = true;
	int loop = (end - start + 1) / 2;
	while (loop--) {
		if (num_vec[start] != num_vec[end]) {
			Palindrome = false;
			break;
		}
		start++; end--;
	}
	return Palindrome;
}

//i>j 사용안함.
void set_dp(std::vector<std::vector<bool>>& dp, const std::vector<int>& num_vec) {
	for (int i = 0; i < dp.size(); i++) {
		for (int j = i; j < dp.size(); j++) {
			if (i == j) dp[i][j] = 1;
			else dp[i][j] = is_it_Palindrome(num_vec,i,j);
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
	std::vector<std::vector<bool>> dp(num_cnt, std::vector<bool>(num_cnt));
	set_dp(dp, num_vec);
	std::cin >> question_cnt;
	int start, end;
	while (question_cnt--) {
		std::cin >> start >> end;
		answer_the_question(dp, start, end);
	}
	return 0;
}