#include<iostream>
#include<vector>
using Map = std::vector<std::vector<std::pair<int, int>>>;

void set_bus_map(Map& bus_map, int bus_cnt) {
	int start, end, cost;
	while (bus_cnt--) {
		std::cin >> start >> end >> cost;
		bus_map[start].push_back(std::make_pair(end, cost));
	}
}

int get_min_index(const std::vector<int>& cost_map, const int& above_this,const std::vector<bool>& visit) {
	int min = 2100000000, min_index = 0;
	for (int i = 0; i < cost_map.size(); i++) {
		if (cost_map[i] >= above_this && cost_map[i] < min) {
			if (!visit[i]) {
				min = cost_map[i];
				min_index = i;
			}
		}
	}
	return min_index;
}

void print_min_cost_from_start_to_goal(const Map& bus_map, const int& city_cnt) {
	int start, goal, now;
	std::cin >> start >> goal;
	std::vector<int> cost_map(city_cnt+1,2100000000);
	std::vector<bool> visit(city_cnt + 1,false);
	cost_map[start] = 0;
	now = start;
	visit[start] = true;
	while (now != goal) {
		for (int i = 0; i < bus_map[now].size(); i++)
			cost_map[bus_map[now][i].first] = std::min(cost_map[bus_map[now][i].first], cost_map[now] + bus_map[now][i].second);
		visit[now] = true;
		now = get_min_index(cost_map, cost_map[now],visit);
	}
	std::cout << cost_map[goal];
}



int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int city_cnt, bus_cnt;
	std::cin >> city_cnt >> bus_cnt;
	Map bus_map(city_cnt+1);
	set_bus_map(bus_map, bus_cnt);
	print_min_cost_from_start_to_goal(bus_map, city_cnt);
	return 0;
}