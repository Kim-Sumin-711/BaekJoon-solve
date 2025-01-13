#include<iostream>
#include<vector>
#include<algorithm>

void set_tri(const int& tri_size, std::vector<std::vector<short>>& tri) {
	short tmp=0;
	for (int i = 1; i < tri_size+1; i++) {
		for (int j = 0; j < i; j++) {
			std::cin >> tmp;
			tri[i].push_back(tmp);
		}
	}
}

void sol(const int& tri_size,const std::vector<std::vector<short>>& tri) {
	std::vector<std::vector<int>> sum_dp(tri_size+1);
	sum_dp[1].push_back(tri[1][0]);
	for (int level = 2; level < tri_size+1; level++) {
		sum_dp[level].push_back(tri[level][0] + sum_dp[level - 1][0]);
		for (int col = 1; col < level - 1; col++) {
			sum_dp[level].push_back(tri[level][col] + std::max(sum_dp[level - 1][col - 1], sum_dp[level - 1][col]));
		}
		sum_dp[level].push_back(tri[level][level - 1] + sum_dp[level - 1][level - 2]);
	}
	std::cout << *std::max_element(sum_dp[tri_size].begin(), sum_dp[tri_size].end());
}

int main(void){
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int tri_size;
	std::cin >> tri_size;
	std::vector<std::vector<short>> tri(tri_size+1);
	set_tri(tri_size, tri);
	sol(tri_size, tri);
	return 0;
}