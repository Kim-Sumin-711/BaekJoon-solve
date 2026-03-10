#include<iostream>
#include<vector>
#include<string>
#include<cmath>
void sol(const std::string& a, const std::string& b) {
	std::vector<std::vector<int>> LCS_len_dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));
	for (int r = 1; r < a.size() + 1; r++) {
		for (int c = 1; c < b.size() + 1; c++) {
			if (a[r - 1] == b[c - 1]) 
				//위, 왼쪽 dp값이 왼쪽 대각선보다 작을 수가 없음.
				//문자를 하나씩만 추가하니까...
				LCS_len_dp[r][c] = LCS_len_dp[r - 1][c - 1] + 1;
			
			else 
				LCS_len_dp[r][c] = std::max(LCS_len_dp[r - 1][c], LCS_len_dp[r][c - 1]);
		}
	}
	std::cout << LCS_len_dp[a.size()][b.size()] << "\n";

	//backtracking
	int r = a.size(), c = b.size();
	std::vector<char> LCS;
	while (r > 0 && c > 0) {
		if (a[r - 1] == b[c - 1]) {
			LCS.push_back(a[r - 1]);
				r--; c--;
		}
		else {
			if (LCS_len_dp[r - 1][c] >= LCS_len_dp[r][c - 1])
				r--;
			
			else c--;
		}
	}


	for (int i = LCS.size() - 1; i > -1; i--) {
		std::cout << LCS[i];
	}

}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::string a, b;
	std::cin >> a >> b;
	sol(a, b);
	return 0;
}