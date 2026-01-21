#include<iostream>
#include<vector>
#include<algorithm>
using Roads = std::vector<std::vector<int>>;

void set_road_vec(Roads& road_vec, int road_cnt) {
	int s, e, c;
	while (road_cnt--) {
		std::cin >> s >> e >> c;
		road_vec.push_back({ s,e,c });
	}
}

bool compare_roads(const std::vector<int>& road1, const std::vector<int>& road2) {
	return road1[2] < road2[2];
}

//for Union-find
int who_is_your_root_node(int node_num, std::vector<int>& parent) {
	if (node_num == parent[node_num]) return node_num;
	else {
		//save the root node num and return
		parent[node_num] = who_is_your_root_node(parent[node_num], parent);
		return parent[node_num];
	}
}

bool unite(std::vector<int>& parent, std::vector<int>& size, int a_node, int b_node) {
	int a_root = who_is_your_root_node(a_node, parent), b_root = who_is_your_root_node(b_node, parent);
	//already they are in the same tree.
	//cycle!!!
	if (a_root == b_root) return false;
	else {
		//always size[a_root] > size[b_root] ==> merge B_node to a_node tree
		if (size[a_root] < size[b_root]) {
			int temp = a_root;
			a_root = b_root;
			b_root = temp;
		}
		//save a_root node num in parent[b_root]
		parent[b_root] = a_root;
		size[a_root] += size[b_root];
		return true;
	}
}

void sol(const Roads road_vec, int home_cnt) {
	int road_cnt = 0;
	int total_cost = 0;
	int cost_of_the_most_expensive_road = 0;
	//Okay. I got soooo many TLE issue.
	//Let me try Union-Find.
	std::vector<int> parent(home_cnt + 1, 0);
	for (int i = 1; i < home_cnt + 1; i++) {
		parent[i] = i;
	}
	//DSU size. for each root node. (node cnt in a tree)
	std::vector<int> size(home_cnt + 1, 1);

	for (int road = 0; road < road_vec.size(); road++) {
		int node1 = road_vec[road][0], node2 = road_vec[road][1];
		bool merge_success = unite(parent, size, node1, node2);
		if (merge_success) {
			total_cost += road_vec[road][2];
			road_cnt++;
			if (cost_of_the_most_expensive_road < road_vec[road][2]) {
				cost_of_the_most_expensive_road = road_vec[road][2];
			}
		}
		if (road_cnt == home_cnt - 1) break;
	}
	//MST Detected
	//next, delete the most expensive road
	//As MST is tree, it will be separted to two section.
	//Also they are also MST
	total_cost -= cost_of_the_most_expensive_road;
	std::cout << total_cost;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int home_cnt, road_cnt;
	std::cin >> home_cnt >> road_cnt;
	Roads road_vec;
	set_road_vec(road_vec, road_cnt);
	std::sort(road_vec.begin(), road_vec.end(), compare_roads);
	sol(road_vec,home_cnt);
	return 0;
}