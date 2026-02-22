#include<iostream>
#include<vector>
int main(void) {
	int node_cnt; std::cin >> node_cnt;
	short root_node = 0;
	std::vector<short> parent_node_vec(node_cnt);
	for (short n = 0; n < node_cnt; n++) {
		short parent; std::cin >> parent;
		if (parent == -1) {
			parent_node_vec[n] = n;
			root_node = n;
		}
		else
			parent_node_vec[n] = parent;
	}
	short deleted_node; std::cin >> deleted_node;
	if (deleted_node == root_node) {
		std::cout << 0;
	}
	else {
		parent_node_vec[deleted_node] = -1;
		for (short n = 0; n < node_cnt; n++) {
			short current_node = n;
			while (parent_node_vec[current_node] != root_node) {
				if (parent_node_vec[current_node] == -1) {
					parent_node_vec[n] = -1;
					break;
				}
				else {
					current_node = parent_node_vec[current_node];
				}
			}
		}

		int leaf_cnt = 0;
		for (int n = 0; n < node_cnt; n++) {
			bool leaf_node = true;
			if (parent_node_vec[n] == -1)
				continue;
			for (int n2 = 0; n2 < node_cnt; n2++) {
				if (n2 == n) continue;
				if (parent_node_vec[n2] == n) {
					leaf_node = false;
					break;
				}
			}
			if (leaf_node == true) leaf_cnt++;
		}
		std::cout << leaf_cnt;
	}
	return 0;
}