#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

//https://edder773.tistory.com/271 를 참고함.
//먼저 아무 노드를 선택하고, 그로부터 가장 먼 노드를 찾아낸다. 이름을 N이라고 하자.
//그리고 N으로부터 가장 거리가 먼 노드를 찾아낸다. M이라고 하자.
//트리의 지름은 N과 M사이의 거리이다.


using TREE = std::unordered_map<int, std::vector<std::pair<int, int>>>;

void setup_tree(TREE& tree, int node_cnt) {
	int n1, n2, c;
	while (--node_cnt) {
		std::cin >> n1;
		while (true) {
			std::cin >> n2;
			if (n2 == -1)break;
			else {
				std::cin >> c;
				tree[n1].push_back(std::make_pair(n2, c));
				tree[n2].push_back(std::make_pair(n1, c));
			}
		}
	}
}
//{dis,num}
std::pair<int, int> get_the_most_far_node_info(const int& target, TREE& tree, const int& node_cnt) {
	std::vector<int>cost_vec(node_cnt + 1, -1);
	cost_vec[target] = 0;
	std::priority_queue<std::pair<int, int>> node_qu;
	node_qu.push({ cost_vec[target],target });
	std::pair<int, int> now;
	while (!node_qu.empty()) {
		now = node_qu.top();
		node_qu.pop();
		if (now.first < cost_vec[now.second]) continue;
		if (tree.find(now.second) != tree.end()) {
			for (const std::pair<int, int>& line : tree[now.second]) {
				//한 점에서 시작해서 임의의 어떤 노드로 이동하는 경로는 하나뿐임.
				//그래서 한 점에 다시 한번 방문해서 최대거리가 갱신되는 경우는 없음.
				if (cost_vec[line.first] != -1) continue;
				if (cost_vec[line.first] < cost_vec[now.second] + line.second) {
					cost_vec[line.first] = cost_vec[now.second] + line.second;
					node_qu.push(std::make_pair(cost_vec[line.first], line.first));
				}
			}
		}
	}
	int max = -1, max_idx = -1;
	for (int node = 1; node < node_cnt + 1; node++) {
		if (cost_vec[node] > max) {
			max = cost_vec[node];
			max_idx = node;
		}
	}
	return std::make_pair(max, max_idx);
}

int get_diameter_of_tree(TREE& tree, const int& node_cnt) {
	int start_node = 1;
	int far_node = get_the_most_far_node_info(start_node, tree, node_cnt).second;
	int res = get_the_most_far_node_info(far_node, tree, node_cnt).first;
	return res;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int node_cnt;
	std::cin >> node_cnt;
	TREE tree_map;
	setup_tree(tree_map, node_cnt);
	std::cout << get_diameter_of_tree(tree_map, node_cnt);
	return 0;
}