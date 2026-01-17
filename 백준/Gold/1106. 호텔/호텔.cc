#include<iostream>
#include<vector>

void set_cost_and_customer_vec(std::vector<std::pair<int, int>>& cost_and_customer_vec, int city_cnt) {
	for (int i = 0; i < city_cnt; i++) {
		std::cin >> cost_and_customer_vec[i].first >> cost_and_customer_vec[i].second;
	}
}

void sol(const std::vector<std::pair<int, int>>& cost_and_customer_vec, int customer_cnt_goal) {
	std::vector<int> dp(100001, 0);
	for (const std::pair<int, int>& city : cost_and_customer_vec) {
		if (dp[city.first] < city.second) {
			dp[city.first] = city.second;
		}
	}

	for (int w = 1; w < 100001; w++) {
		if (dp[w] == 0) continue;
		else if (dp[w] >= customer_cnt_goal) {
			std::cout << w;
			break;
		}
		else {
			for (const std::pair<int, int>& city : cost_and_customer_vec) {
				if (dp[city.first + w] < city.second + dp[w]) {
					dp[city.first + w] = city.second + dp[w];
				}
			}
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int customer_cnt_goal, city_cnt;
	std::cin >> customer_cnt_goal >> city_cnt;
	//first : cost, second : customer
	std::vector<std::pair<int, int>> cost_and_customer_vec(city_cnt);
	set_cost_and_customer_vec(cost_and_customer_vec, city_cnt);
	sol(cost_and_customer_vec, customer_cnt_goal);

	return 0;
}