#include<iostream>
#include<unordered_map>
#include<queue>
using Graph = std::unordered_map<int, std::vector<std::pair<int, int>>>;
int INF = 2100000000;

void set_bus_info(Graph& info, int bus_cnt) {
	while (bus_cnt--) {
		int start, goal, cost; std::cin >> start >> goal >> cost;
		if (info.find(start) != info.end()) {
			bool found = false;
			for (int i = 0; i < info[start].size(); i++) {
				if (info[start][i].first ==goal) {
					if (info[start][i].second > cost) info[start][i].second = cost;
					found = true;
					break;
				}
			}
			if (!found) info[start].push_back(std::make_pair(goal, cost));

		}
		else info[start].push_back(std::make_pair(goal, cost));
	}
}

void print_min_distances_from_start(Graph& bus_info, const int& start, const int& city_cnt) {
	std::vector<int> city(city_cnt+1, INF);
	city[start] = 0;
	std::queue<int> queue;
	queue.push(start);
	while (!queue.empty()) {
		int now = queue.front();
		queue.pop();
		for (auto bus = bus_info[now].begin(); bus != bus_info[now].end(); bus++) {
			if (city[bus->first] > city[now] + bus->second) {
				queue.push(bus->first);
				city[bus->first] = city[now] + bus->second;
			}
		}
	}
	for (int i = 1; i < city_cnt + 1; i++) {
		if (city[i] == INF) std::cout << 0 << " ";
		else std::cout << city[i] << " ";
	}
}

void set_result(Graph& bus_info, int city_cnt) {
	for (int start = 1; start < city_cnt+1; start++) {
		print_min_distances_from_start(bus_info, start, city_cnt);
		std::cout << "\n";
	}
}


int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int city_cnt, bus_cnt; std::cin >> city_cnt >> bus_cnt;
	Graph bus_info;
	set_bus_info(bus_info, bus_cnt);
	set_result(bus_info, city_cnt);
	return 0;
}