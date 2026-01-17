#include<iostream>
#include<vector>
#include<algorithm>

void set_edge_vec(std::vector<std::vector<int>>& edge_vec, int edge_cnt) {
	for (int i = 0; i < edge_cnt; i++) {
		std::cin >> edge_vec[i][0] >> edge_vec[i][1] >> edge_vec[i][2];
	}
}

bool compare_edge(const std::vector<int>& edge1, const std::vector<int>& edge2) {
	return edge1[2] < edge2[2];
}

void sol(const std::vector<std::vector<int>>& edge_vec, int node_cnt) {
	std::vector<int> leader_node_num_for_each_nodes(node_cnt + 1, -1);
	int minimum_val_of_spanning_tree = 0;
	for (int i = 0; i < edge_vec.size(); i++) {
		std::vector<int> selected_edge = edge_vec[i];
		if (leader_node_num_for_each_nodes[selected_edge[0]] == -1 && leader_node_num_for_each_nodes[selected_edge[1]] == -1) {
			leader_node_num_for_each_nodes[selected_edge[0]] = selected_edge[0];
			leader_node_num_for_each_nodes[selected_edge[1]] = selected_edge[0];
			minimum_val_of_spanning_tree += selected_edge[2];
		}
		else if(leader_node_num_for_each_nodes[selected_edge[0]] == -1 || leader_node_num_for_each_nodes[selected_edge[1]] == -1) {
			if (leader_node_num_for_each_nodes[selected_edge[0]] == -1) 
				leader_node_num_for_each_nodes[selected_edge[0]] = leader_node_num_for_each_nodes[selected_edge[1]];
			else
				leader_node_num_for_each_nodes[selected_edge[1]] = leader_node_num_for_each_nodes[selected_edge[0]];
			minimum_val_of_spanning_tree += selected_edge[2];
		}
		else {
			//it makes cycle. --> not tree.
			if (leader_node_num_for_each_nodes[selected_edge[0]] == leader_node_num_for_each_nodes[selected_edge[1]]) {
				continue;
			}
			//merge_two_trees
			else {
				int temp = leader_node_num_for_each_nodes[selected_edge[1]];
				leader_node_num_for_each_nodes[selected_edge[1]] = leader_node_num_for_each_nodes[selected_edge[0]];
				for (int i = 1; i < node_cnt + 1; i++) {
					if (leader_node_num_for_each_nodes[i] == temp)
						leader_node_num_for_each_nodes[i] = leader_node_num_for_each_nodes[selected_edge[0]];
				}
				minimum_val_of_spanning_tree += selected_edge[2];
			}
		}
	}
	std::cout << minimum_val_of_spanning_tree;

}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int node_cnt, edge_cnt;
	std::cin >> node_cnt >> edge_cnt;
	//node1, node2, cost
	std::vector<std::vector<int>> edge_vec(edge_cnt, std::vector<int>(3));
	set_edge_vec(edge_vec, edge_cnt);
	std::sort(edge_vec.begin(), edge_vec.end(), compare_edge);
	sol(edge_vec, node_cnt);
	return 0;
}