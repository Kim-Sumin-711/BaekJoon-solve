#include<iostream>
#include<vector>

void set_house_color_cost_vec(std::vector<std::vector<short>>& vec) {
	for (std::vector<short>& elem_vec : vec)
		for (short& elem : elem_vec)
			std::cin >> elem;
}

void set_cost_dp_about_this_house(const std::vector<std::vector<short>>& house_cost_vec, const int& house_cnt, std::vector<std::vector<int>>& cost_dp) {
	int red = house_cost_vec[house_cnt][0], green = house_cost_vec[house_cnt][1], blue = house_cost_vec[house_cnt][2];
	cost_dp[house_cnt] = { red + std::min(cost_dp[house_cnt - 1][1],cost_dp[house_cnt - 1][2]), green + std::min(cost_dp[house_cnt - 1][0],cost_dp[house_cnt - 1][2]),blue + std::min(cost_dp[house_cnt - 1][0],cost_dp[house_cnt - 1][1]) };
}

void sol(const std::vector<std::vector<short>>& house_cost_vec) {
	std::vector<std::vector<int>> cost_dp(house_cost_vec.size(), std::vector<int>(3));
	cost_dp[0] = { house_cost_vec[0][0],house_cost_vec[0][1],house_cost_vec[0][2] };
	for (int house = 1; house < house_cost_vec.size(); house++)
		set_cost_dp_about_this_house(house_cost_vec, house, cost_dp);

	std::cout << std::min(std::min(cost_dp[house_cost_vec.size() - 1][0], cost_dp[house_cost_vec.size() - 1][1]), cost_dp[house_cost_vec.size() - 1][2]);
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int house_cnt;
	std::cin >> house_cnt;
	std::vector<std::vector<short>> house_color_cost(house_cnt, std::vector<short>(3));
	set_house_color_cost_vec(house_color_cost);
	sol(house_color_cost);
	return 0;
}