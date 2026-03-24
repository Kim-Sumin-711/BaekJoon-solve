#include<iostream>
#include<vector>

void set_graph(std::vector<int>& graph) {
	for (int i = 1; i < graph.size(); i++) {
		std::cin >> graph[i];
	}
}

bool are_you_insider(int stu, const std::vector<int>& graph, std::vector<bool>& insider_vec, std::vector<bool>& visit) {
	visit[stu] = true;
	std::vector<int> dp;
	dp.push_back(stu);
	int current_node = graph[stu];
	bool you_are_insider = false;
	while (true) {
		if (current_node == stu) {
			you_are_insider = true;
			for (const int& insiders : dp) {
				insider_vec[insiders] = true;
			}
			break;
		}
		else if (visit[current_node] == true) {
			bool in_the_insider_group = false;
			for (int i = 0; i < dp.size(); i++) {
				if (in_the_insider_group == false && dp[i] == current_node) {
					in_the_insider_group = true;
					insider_vec[dp[i]] = true;
				}
				else if (in_the_insider_group == true) insider_vec[dp[i]] = true;
			}
			break;
		}
		else if (insider_vec[current_node]) {
			break;
		}
		else {
			visit[current_node] = true;
			dp.push_back(current_node);
			current_node = graph[current_node];
		}
	}
	return insider_vec[stu];
}

int count_outsider_cnt(void) {
	int stu_cnt; std::cin >> stu_cnt;
	std::vector<int> graph(stu_cnt + 1);
	set_graph(graph);
	std::vector<bool> insider_vec(stu_cnt + 1, false);
	std::vector<bool> visit(graph.size(), false);
	int outsider_cnt = 0;
	for (int stu = 1; stu < stu_cnt + 1; stu++) {
		if (insider_vec[stu] == true) continue;
		else {
			if (visit[stu] == true) outsider_cnt++;
			else if (are_you_insider(stu, graph, insider_vec,visit) == true) continue;
			else outsider_cnt++;	
		}
	}
	return outsider_cnt;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int T; std::cin >> T;
	while (T--) {
		std::cout << count_outsider_cnt() << "\n";
	}
	return 0;
}