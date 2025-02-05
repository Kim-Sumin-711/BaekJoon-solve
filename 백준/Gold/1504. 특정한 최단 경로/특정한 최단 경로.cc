#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using MAP = std::unordered_map<int, std::vector<std::pair<int, int>>>;
int INF = 2100000000;


void setup_map(MAP& map, int line_cnt,const int& node_cnt) {
	int start, goal, cost;
	while (line_cnt--) {
		std::cin >> start >> goal >> cost;
		map[start].push_back(std::make_pair(goal, cost));
		map[goal].push_back(std::make_pair(start, cost));
	}
	for (int i = 1; i < node_cnt + 1; i++) {
		std::sort(map[i].begin(), map[i].end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a < b; });
	}
}

int find_node_num_has_min_cost(const std::vector<int>& costs, const std::vector<bool>& visit)  {
	int min_cost = INF, min_idx = -1;
	for (int i = 1; i < costs.size(); i++) {
		if (!visit[i]) {
			if (costs[i] < min_cost) {
				min_cost = costs[i];
				min_idx = i;
			}
		}
	}
	return min_idx;
}

std::vector<int> get_dis_info(const int& target, const int& goal1, const int& goal2, const int& goal3, MAP& map, const int& node_cnt) {
	std::vector<int> node_cost(node_cnt + 1, INF);
	std::vector<bool> visit(node_cnt + 1, false);
	node_cost[target] = 0;
	visit[target] = true;
	int now = target;
	while (true) {
		
		for (const std::pair<int, int>& line_info : map[now]) {
			if (!visit[line_info.first]) {
				if (node_cost[line_info.first] > node_cost[now] + line_info.second) {
					node_cost[line_info.first] = node_cost[now] + line_info.second;
				}
			}
		}	
		now = find_node_num_has_min_cost(node_cost, visit);
		if (now == -1) break;
		else visit[now] = true;
	}
	std::vector<int> res = {node_cost[goal1],node_cost[goal2],node_cost[goal3]};
	return res;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int node_cnt, line_cnt;
	std::cin >> node_cnt >> line_cnt;
	if (line_cnt == 0) {
		std::cout << -1;
		return 0;
	}
	MAP node_map;
	setup_map(node_map, line_cnt,node_cnt);
	int must1, must2;
	std::cin >> must1 >> must2;
	std::vector<int> m1_dis_info = get_dis_info(must1, 1, must2, node_cnt, node_map, node_cnt);
	std::vector<int> m2_dis_info = get_dis_info(must2, 1, must1, node_cnt, node_map, node_cnt);
	
	if (m1_dis_info[1] == INF)
		std::cout << -1;

	else {
		int ans1=INF, ans2=INF;
		if (m1_dis_info[0] != INF && m2_dis_info[2] != INF)
			ans1 = m1_dis_info[0] + m1_dis_info[1] + m2_dis_info[2];
		if (m2_dis_info[0] != INF && m1_dis_info[2] != INF)
			ans2 = m2_dis_info[0] + m2_dis_info[1] + m1_dis_info[2];
		if(ans1==INF && ans2==INF) {
			std::cout << -1;
			return 0;
		}
		std::cout << std::min(ans1, ans2);

	}
	return 0;
}