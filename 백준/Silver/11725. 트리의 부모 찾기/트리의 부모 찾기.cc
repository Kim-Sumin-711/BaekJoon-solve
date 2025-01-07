#include<iostream>
#include<vector>
#include<queue>

void set_tree(std::vector<std::pair<std::vector<int>, int>>& tree, const int& node_cnt) {
	for (int i = 0; i < node_cnt-1; i++) {
		int n1, n2;
		std::cin >> n1 >> n2;
		tree[n1].first.push_back(n2);
		tree[n2].first.push_back(n1);
	}
}

void set_node_level(std::vector<std::pair<std::vector<int>, int>>& tree, const int& node_cnt) {
	std::queue<int> node_qu;
	std::vector<bool>visit(node_cnt + 1,false);
	node_qu.push(1);
	visit[1] = true;
	int now=0,size=0,level = 1;
	while (node_qu.size() != 0) {
		size = node_qu.size();
		while (size--) {
			now = node_qu.front();
			node_qu.pop();
			for (const int& node : tree[now].first) {
				if (!visit[node]) {
					visit[node] = true;
					tree[node].second = level;
					node_qu.push(node);

				}
			}
		}
		level++;
	}
}

int find_your_mom_or_dad(std::vector<std::pair<std::vector<int>, int>>& tree, const int& target_num, const int& node_cnt) {
	for (const int& node : tree[target_num].first) {
		if (tree[node].second < tree[target_num].second)
			return node;
	}
	return -1;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int node_cnt;
	std::cin >> node_cnt;
	std::vector<std::pair<std::vector<int>, int>> tree_info(node_cnt + 1);
	set_tree(tree_info,node_cnt);
	set_node_level(tree_info,node_cnt);
	for (int t = 2; t < node_cnt + 1; t++) {
		std::cout << find_your_mom_or_dad(tree_info, t,node_cnt) << "\n";
	}
	return 0;
}