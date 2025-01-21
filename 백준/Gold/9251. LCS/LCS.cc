#include<iostream>
#include<string>
#include<vector>

int get_LCS_size(const std::string& str1, const std::string& str2, std::vector<std::vector<int>>& dp) {
	for (int r = 0; r < str2.size(); r++) {
		for (int c = 0; c < str1.size(); c++) {
			if (str1[c] == str2[r])
				dp[r + 1][c + 1] = dp[r][c] + 1;
			else
				dp[r + 1][c + 1] = std::max(dp[r][c + 1], dp[r + 1][c]);
		}
	}
	return dp[str2.size()][str1.size()];
}

void swap_str(std::string& str1, std::string& str2) {
	std::string tmp = str1;
	str1 = str2;
	str2 = tmp;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::string str1, str2;
	std::cin >> str1 >> str2;
	if (str1.size() < str2.size())
		swap_str(str1, str2);
	std::vector<std::vector<int>> dp_vec(str2.size() + 1,std::vector<int>(str1.size() + 1)) ;
	std::cout << get_LCS_size(str1, str2, dp_vec);
	return 0;
}