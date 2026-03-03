#include<iostream>
#include<vector>
#include<queue>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int singer_cnt, pd_cnt; std::cin >> singer_cnt >> pd_cnt;
	std::vector<std::vector<int>> rule(singer_cnt + 1);
	std::vector<std::vector<int>> post_singers(singer_cnt + 1);
	std::vector<bool> included(singer_cnt + 1, false);
	while (pd_cnt--) {
		int loop; std::cin >> loop;
		int front; std::cin >> front;
		loop--;
		while (loop--) {
			int back; std::cin >> back;
			rule[back].push_back(front);
			post_singers[front].push_back(back);
			front = back;
		}
	}
	std::queue<int> qu;
	for (int singer = 1; singer < singer_cnt + 1; singer++) {
		if (rule[singer].empty() == true) qu.push(singer);
	}

	std::vector<int> singer_formation;
	while (qu.empty() == false) {
		int now_singer = qu.front();
		qu.pop();
		if (included[now_singer] == true) continue;
		bool get_ready = true;
		for (int front_singer : rule[now_singer]) {
			if (included[front_singer] == false) {
				get_ready = false;
				break;
			}
		}
		if (get_ready == true) {
			singer_formation.push_back(now_singer);
			included[now_singer] = true;
			for (int post : post_singers[now_singer]) {
				if(included[post] == false)
					qu.push(post);
			}
		}
	}
	if (singer_formation.size() != singer_cnt) std::cout << 0;
	else {
		for (int singer : singer_formation) {
			std::cout << singer << "\n";
		}
	}
 	return 0;
}