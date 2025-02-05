#include<iostream>
#include<queue>
#include<unordered_map>
using MAP = std::unordered_map<int, std::unordered_map<int, int>>;
int INF = 2100000000;

void setup_map(MAP& map, int line_cnt) {
	int start, goal, cost;
	while (line_cnt--) {
		std::cin >> start >> goal >> cost;
		if (map[start].find(goal) == map[start].end()) {
			map[start].insert(std::make_pair(goal, cost));
		}
		else {
			if (map[start][goal] > cost) {
				map[start][goal] = cost;
			}
		}
	}
}

void setup_node_dis_vec(const int& start, MAP& map, std::vector<int>& dis_vec) {
	std::priority_queue<std::pair<int, int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> node_queue;
	node_queue.push(std::make_pair(0,start));
	std::pair<int, int>now;
	while (node_queue.size() != 0) {
		now = node_queue.top();
		node_queue.pop();
		if (dis_vec[now.second] < now.first) continue;
		for (const std::pair<int, int>& line_info : map[now.second]) {
			if (dis_vec[line_info.first] > dis_vec[now.second] + line_info.second) {
				dis_vec[line_info.first] = dis_vec[now.second] + line_info.second;
				node_queue.push(std::make_pair(dis_vec[line_info.first], line_info.first));
			}
		}
	}
}

void print_each_dis_of_nodes(const int& start, MAP& map, const int& node_cnt) {
	std::vector<int> node_dis(node_cnt+1,INF);
	node_dis[start] = 0;
	setup_node_dis_vec(start, map, node_dis);
	for (int node = 1; node < node_cnt+1; node++) {
		if (node_dis[node] == INF)	std::cout << "INF\n";
		else  std::cout << node_dis[node] << "\n";
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int node_cnt, line_cnt, start;
	std::cin >> node_cnt >> line_cnt >> start;
	MAP map;
	setup_map(map, line_cnt);
	print_each_dis_of_nodes(start, map, node_cnt);
	return 0;
}