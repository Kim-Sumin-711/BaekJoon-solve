#include<iostream>
#include<vector>
#include<queue>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int stu_cnt, compare_cnt; std::cin >> stu_cnt >> compare_cnt;
	std::vector<std::vector<int>> post_vec(stu_cnt + 1);
	std::vector<int> prior_cnt(stu_cnt + 1, 0);
	std::queue<int> get_in_the_formation_dawg;
	while (compare_cnt--) {
		int front, back; std::cin >> front >> back;
		post_vec[front].push_back(back);
		prior_cnt[back]++;
	}
	for (int i = 1; i < stu_cnt + 1; i++) {
		if (prior_cnt[i] == 0) get_in_the_formation_dawg.push(i);
	}
	while (get_in_the_formation_dawg.empty() == false) {
		int dawg = get_in_the_formation_dawg.front();
		get_in_the_formation_dawg.pop();
		std::cout << dawg << ' ';
		for (int post : post_vec[dawg]) {
			if (prior_cnt[post] > 0)
				prior_cnt[post]--;
			if (prior_cnt[post] == 0) get_in_the_formation_dawg.push(post);
		}
	}

	return 0;
}