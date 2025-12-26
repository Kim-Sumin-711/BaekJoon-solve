#include<iostream>
#include<vector>
#include<algorithm>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int problem_cnt;
	std::cin >> problem_cnt;
	std::vector<std::pair<int,int>> trial_cnt_vec;
	for (int i = 0; i < problem_cnt; i++) {
		int trial_cnt = 0;
		std::cin >> trial_cnt;
		trial_cnt_vec.push_back({ i + 1,trial_cnt });
	}
	if (problem_cnt == 1) {
		if (trial_cnt_vec[0].second == 0) std::cout << 1;
		else std::cout << -1;
		return 0;
	}
	std::sort(trial_cnt_vec.begin(), trial_cnt_vec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second < b.second; });
	if (trial_cnt_vec[0].second != 0) {
		std::cout << -1;
		return 0;
	}
	int p1 = 0, p2 = 0;
	for (int i = 0; i < problem_cnt; i++) {
		if (trial_cnt_vec[i].second != 0) {
			p2 = i;
			break;
		}
	}
	std::vector<int> ans_vec;
	while (p1 < problem_cnt) {
		//correct
		if (trial_cnt_vec[p1].second == 0) {
			ans_vec.push_back(trial_cnt_vec[p1].first);
			p1++;
		}
		else {
			std::cout << -1;
			return 0;
		}
		if (p1 == problem_cnt) break;
		if (p1 == problem_cnt - 1) {
			if (trial_cnt_vec[p1].second != 1) {
				std::cout << -1;
				return 0;
			}
		}

		//wrong
		trial_cnt_vec[p2].second--;
		ans_vec.push_back(trial_cnt_vec[p2].first);
		if (trial_cnt_vec[p2].second == 0) p2++;
	}
	for (int& ans : ans_vec) {
		std::cout << ans << "\n";
	}
	return 0;
}