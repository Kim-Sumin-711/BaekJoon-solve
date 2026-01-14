#include<iostream>
#include<vector>
#include<queue>
void set_parent_num_vec(const std::vector<std::vector<int>>& graph, std::vector<int>& parent_num_vec, int root_num) {
	std::queue<int> traversal_qu;
	traversal_qu.push(root_num);
	//there's no parent --> -1
	parent_num_vec[root_num] = -1;
	while (traversal_qu.empty() == false) {
		int now = traversal_qu.front();
		traversal_qu.pop();
		for (const int& node : graph[now]) {
			if (node != parent_num_vec[now]) {
				parent_num_vec[node] = now;
				traversal_qu.push(node);
			}
		}
	}
}

int set_children_cnt_vec_and_get_children_cnt(const std::vector<std::vector<int>>& graph, std::vector<int>& children_cnt_vec, const std::vector<int>& parents_vec, int now_node_num) {
	int children_cnt = 0;
	for (int children_node : graph[now_node_num]) {
		if (parents_vec[now_node_num] == children_node) {
			continue;
		}
		else {
			if (children_cnt_vec[children_node] == -1) {
				children_cnt += set_children_cnt_vec_and_get_children_cnt(graph, children_cnt_vec, parents_vec, children_node);
			}
			else {
				children_cnt += children_cnt_vec[children_node];
			}
		}
		
	}
	//itself --> +1
	children_cnt_vec[now_node_num] = children_cnt+1;
	return children_cnt_vec[now_node_num];
}

void handle_querys(int query_cnt, std::vector<int>& children_cnt_vec) {
	while (query_cnt--) {
		int node_num;
		std::cin >> node_num;
		std::cout << children_cnt_vec[node_num] << "\n";
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int node_cnt, root_num, query_cnt;
	std::cin >> node_cnt >> root_num >> query_cnt;
	std::vector<int> parent_num_vec(node_cnt + 1, -1), children_cnt_vec(node_cnt + 1, -1);
	std::vector<std::vector<int>> graph(node_cnt + 1);
	for (int i = 1; i < node_cnt; i++) {
		int node_1, node_2;
		std::cin >> node_1 >> node_2;
		graph[node_1].push_back(node_2); graph[node_2].push_back(node_1);
	}
	set_parent_num_vec(graph, parent_num_vec, root_num);
	for (int i = 1; i < node_cnt + 1; i++) {
		if (children_cnt_vec[i] != -1) continue;
		else set_children_cnt_vec_and_get_children_cnt(graph, children_cnt_vec, parent_num_vec, i);
	}
	handle_querys(query_cnt, children_cnt_vec);

	return 0;
}