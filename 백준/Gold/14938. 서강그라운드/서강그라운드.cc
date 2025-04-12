#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using Map = std::unordered_map<int, std::vector<std::pair<int, int>>>;
int INF = 2100000000;

struct compare_nodes {
	bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.second > b.second;
	}
};

void set_nodes(std::vector<int>& nodes) {
	for (auto iter = nodes.begin(); iter != nodes.end(); iter++)
		std::cin >> *iter;
}

void set_roads(Map& roads, const int& road_cnt) {
	for (int _ = 0; _ < road_cnt; _++) {
		int start, goal, cost; std::cin >> start >> goal >> cost;
		if (roads.find(start-1) != roads.end()) roads[start-1].push_back(std::make_pair(goal-1, cost));
		else roads[start-1] = { std::make_pair(goal-1,cost) };
		if (roads.find(goal - 1) != roads.end()) roads[goal - 1].push_back(std::make_pair(start - 1, cost));
		else roads[goal - 1] = { std::make_pair(start - 1,cost) };
	}
}

int get_item_cnt(const int& start, const std::vector<int>& nodes, Map& roads, const int& range) {
	int item_cnt = 0;
	std::vector<int> distance(nodes.size(),INF); 
	distance[start] = 0;

	std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, compare_nodes> pri_queue;
	pri_queue.push(std::make_pair(start,0));

	while (!pri_queue.empty()) {
		int now = pri_queue.top().first;
		int now_cost = pri_queue.top().second;
		pri_queue.pop();

		for (auto iter = roads[now].begin(); iter != roads[now].end(); iter++) {
			if (distance[iter->first] > distance[now] + iter->second) {
				distance[iter->first] = distance[now] + iter->second;
				pri_queue.push(std::make_pair(iter->first, distance[iter->first]));
			}
		}
	}

	for (int i = 0; i<distance.size(); i++) {
		if (distance[i] <= range) item_cnt += nodes[i];
	}
	return item_cnt;
}

void sol(const std::vector<int>& nodes, Map& roads, const int& range) {
	int maximum_of_item_cnt = 0;
	for (int start_node = 0; start_node < nodes.size(); start_node++) {
		maximum_of_item_cnt = std::max(maximum_of_item_cnt, get_item_cnt(start_node, nodes, roads, range));
	}
	std::cout << maximum_of_item_cnt;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int node_cnt, range, road_cnt; std::cin >> node_cnt >> range >> road_cnt;
	std::vector<int> nodes(node_cnt);
	Map roads;
	set_nodes(nodes);
	set_roads(roads, road_cnt);
	sol(nodes, roads, range);


	return 0;
}