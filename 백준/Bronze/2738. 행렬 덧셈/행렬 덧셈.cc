#include<iostream>
#include<vector>

void set_vector(std::vector<std::vector<int>>& vec) {
	for (std::vector<int>& row : vec) {
		for (int& elem : row) {
			std::cin >> elem;
		}
	}
}

void sol(const std::vector<std::vector<int>>& avec, const std::vector<std::vector<int>>& bvec) {
	for (int i = 0; i < avec.size(); i++) {
		for (int j = 0; j < avec[0].size(); j++) {
			std::cout << avec[i][j] + bvec[i][j] << ' ';
		}
		std::cout << "\n";
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int a, b;
	std::cin >> a >> b;
	std::vector<std::vector<int>> avec(a, std::vector<int>(b, 0)), bvec(a, std::vector<int>(b, 0));
	set_vector(avec);
	set_vector(bvec);
	sol(avec, bvec);
	return 0;
}
