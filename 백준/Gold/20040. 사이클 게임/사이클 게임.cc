#include<iostream>
#include<vector>

int find(std::vector<int>& root_node_vec, int node) {
	if (root_node_vec[node] == node) return node;
	else {
		root_node_vec[node] = find(root_node_vec, root_node_vec[node]);
		return root_node_vec[node];
	}
}

//unite two sets. if cycle -> return false; not, return true.
bool unite(std::vector<int>& root_node_vec, std::vector<int>& size, int node1, int node2) {
	//same root node --> this edge makes a cycle.
	int root1 = find(root_node_vec, node1), root2 = find(root_node_vec, node2);
	if (root1==root2) return false;
	else {
		if (size[root1] < size[root2]) {
			int temp = root1;
			root1 = root2;
			root2 = temp;
		}
		size[root1] += size[root2];
		root_node_vec[root2] = root1;
		return true;
	}
}

void sol(std::vector<int>& root_node_vec, std::vector<int>&size,int turn_cnt) {
	int ans = 0;
	while (turn_cnt--) {
		ans++;
		int node1, node2; std::cin >> node1 >> node2;
		int root1 = find(root_node_vec, node1), root2 = find(root_node_vec, node2);
		if (root1 == root2) {
			std::cout << ans;
			return;
		}
		else {
			unite(root_node_vec, size, root1, root2);
		}
	}
	std::cout << 0;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int spot_cnt, turn_cnt; std::cin >> spot_cnt >> turn_cnt;
	std::vector<int> root_node_vec(spot_cnt, 0);
	std::vector<int> size(spot_cnt, 1);
	for (int i = 0; i < spot_cnt; i++) {
		root_node_vec[i] = i;
	}
	sol(root_node_vec,size,turn_cnt);
	return 0;
}