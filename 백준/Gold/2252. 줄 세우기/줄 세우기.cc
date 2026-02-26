#include<iostream>
#include<vector>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int stu_cnt, compare_cnt; std::cin >> stu_cnt >> compare_cnt;
	std::vector<std::vector<int>> post_vec(stu_cnt + 1);
	std::vector<int> prior_cnt(stu_cnt + 1,0);
	std::vector<bool> in_formation(stu_cnt + 1, false);
	while (compare_cnt--) {
		int front, back; std::cin >> front >> back;
		post_vec[front].push_back(back);
		prior_cnt[back]++;
	}
	int students_cnt_in_formation = 0;
	while (students_cnt_in_formation != stu_cnt) {
		for (int i = 1; i < stu_cnt + 1; i++) {
			if (in_formation[i] == false && prior_cnt[i] == 0) {
				students_cnt_in_formation++;
				in_formation[i] = true;
				for (int post : post_vec[i]) {
					if(prior_cnt[post] > 0)
						prior_cnt[post]--;
				}
				std::cout << i << ' ';
				
			}
		}
	}
	return 0;
}