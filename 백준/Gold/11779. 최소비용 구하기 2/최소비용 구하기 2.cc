#include<iostream>
#include<unordered_map>
#include<cmath>
#include<queue>
using MAP = std::vector<std::unordered_map<int, int>>;

bool compare_pair(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}

void set_map(MAP& map, int buscnt) {
	int start, goal, cost;
	while (buscnt--) {
		std::cin >> start >> goal >> cost;
		if (map[start].find(goal) != map[start].end()) {
			map[start][goal] = std::min(cost, map[start][goal]);
		}
		else map[start].insert({ goal,cost });
	}
}

void sol(const MAP& bus_map) {
	int start, goal;
	std::cin >> start >> goal;
	if (start == goal) {
		std::cout << 0 << "\n" << 1 << "\n" << start;
		return;
	}
	//save {before node} in {now node}
	//ex 1->2 : pass_dp[2]=1
	//we can you it when finding out the best way and passed city cnt.
	//we'll check from goal to start
	//1->2->4 : pass_dp[4] is 2 --> pass_dp[2] is 1 --> 1 is start node.
	std::vector<int> city_cost_map(bus_map.size(), 2100000000);
	city_cost_map[start] = 0;
 	std::vector<int> pass(bus_map.size(),-1);

	//for priority queue's sort order.
	auto lambda = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second > b.second; };
	
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(lambda)> Dijkstra_queue(lambda);
	std::pair<int, int> now = { start,0 };
	Dijkstra_queue.push(now);

	while (now.first != goal) {
		for (std::pair<int, int> bus : bus_map[now.first]) {
			if (city_cost_map[bus.first] > bus.second + now.second) {
				city_cost_map[bus.first] = bus.second + now.second;
				pass[bus.first] = now.first;
				Dijkstra_queue.push({ bus.first, city_cost_map[bus.first]});
			}
		}
		//the way to go to the goal point should be present.
		//so if(Dijkstra_queue.empty()) is not required.
		Dijkstra_queue.pop();
		now = Dijkstra_queue.top();
	}
	int city = goal;
	std::vector<int> the_way(1, city);
	while (city != start) {
		city = pass[city];
		the_way.push_back(city);
	}

	//the best cost
	std::cout << city_cost_map[goal] << "\n";
	//cnt of passed citys
	std::cout << the_way.size() << "\n";
	//the way we've passed through
	for (int i = the_way.size() - 1; i > -1; i--) {
		std::cout << the_way[i] << ' ';
	}

}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int city_cnt, bus_cnt;
	std::cin >> city_cnt >> bus_cnt;
	MAP bus_map(city_cnt + 1);
	set_map(bus_map, bus_cnt);
	sol(bus_map);


	return 0;
}