#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using Tree_type = std::unordered_map<char, std::pair<char, char>>;

void set_my_tree(Tree_type& my_tree, const int&node_cnt) {
	char node, left_baby, right_baby;
	for (int i = 0; i < node_cnt; i++) {
		std::cin >> node >> left_baby >> right_baby;
		my_tree[node] = std::make_pair(left_baby, right_baby);
	}
}

void get_preorder_traversal_res(Tree_type& my_tree) {
	char now_node = 'A';
	std::stack<char> node_stack;
	node_stack.push(now_node);
	while (node_stack.size() != 0) {
		now_node = node_stack.top();
		node_stack.pop();
		if (now_node != '.') {
			std::cout << now_node;
			node_stack.push(my_tree[now_node].second);
			node_stack.push(my_tree[now_node].first);
		}
	}
}

void get_inorder_traversal(Tree_type& my_tree) {
	std::unordered_set<char>visit_set;
	char now_node = 'A';
	std::stack<char> node_stack;
	node_stack.push(now_node);
	while (node_stack.size() != 0) {
		now_node = node_stack.top();
		node_stack.pop();
		if (visit_set.find(now_node) == visit_set.end() && now_node!='.') {
			visit_set.insert(now_node);
			node_stack.push(my_tree[now_node].second);
			node_stack.push(now_node);
			node_stack.push(my_tree[now_node].first);
		}
		else {
			if (now_node != '.')
				std::cout << now_node;
		}
	}
}

void get_postorder_traversal(Tree_type& my_tree) {
	std::unordered_set<char>visit_set;
	char now_node = 'A';
	std::stack<char> node_stack;
	node_stack.push(now_node);
	while (node_stack.size() != 0) {
		now_node = node_stack.top();
		node_stack.pop();
		if (visit_set.find(now_node) == visit_set.end() && now_node != '.') {
			visit_set.insert(now_node);
			node_stack.push(now_node);
			node_stack.push(my_tree[now_node].second);
			node_stack.push(my_tree[now_node].first);
		}
		else {
			if (now_node != '.')
				std::cout << now_node;
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int node_cnt;
	std::cin >> node_cnt;
	Tree_type my_tree;
	set_my_tree(my_tree, node_cnt);
	get_preorder_traversal_res(my_tree);
	std::cout << "\n";
	get_inorder_traversal(my_tree);
	std::cout << "\n";
	get_postorder_traversal(my_tree);
	return 0;
}