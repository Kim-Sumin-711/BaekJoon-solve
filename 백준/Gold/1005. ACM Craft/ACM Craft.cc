#include<iostream>
#include<vector>
#include<queue>
#include<functional>
void set_time_table(std::vector<int>& time_table) {
	for (int i = 1; i < time_table.size(); i++) {
		std::cin >> time_table[i];
	}
}

void set_require_vec(std::vector<std::vector<int>>& required_building_vec, int rule_cnt) {
	while (rule_cnt--) {
		int prior, post;
		std::cin >> prior >> post;
		required_building_vec[post].push_back(prior);
	}
}

long long ACF_craft_simulate(int demanded_bn, std::vector<int>& time_table, std::vector<std::vector<int>>& required_building_vec, std::vector<int>& time_dp) {
	if (time_dp[demanded_bn] != -1) {
		return time_dp[demanded_bn];
	}
	else {
		long long sub_install_time = 0;
		for (const int& bn : required_building_vec[demanded_bn]) {
			if (time_dp[bn] == -1) {
				time_dp[bn] = ACF_craft_simulate(bn, time_table, required_building_vec, time_dp);
			}
			if (sub_install_time < time_dp[bn]) {
				sub_install_time = time_dp[bn];
			}
		}
		long long install_time = sub_install_time + time_table[demanded_bn];
		return install_time;
	}
}

long long ACF_craft(void) {
	int building_cnt, rule_cnt; std::cin >> building_cnt >> rule_cnt;

	std::vector<int> time_table(building_cnt+1,0);
	set_time_table(time_table);

	std::vector<std::vector<int>> required_building_vec(building_cnt + 1);
	set_require_vec(required_building_vec, rule_cnt);

	std::vector<int> time_dp(time_table.size(), -1);
	int demanded_building_num; std::cin >> demanded_building_num;
	long long install_time = ACF_craft_simulate(demanded_building_num, time_table, required_building_vec, time_dp);

	
	return install_time;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		std::cout << ACF_craft() << "\n";
	}
	return 0;
}