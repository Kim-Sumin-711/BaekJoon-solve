#include<iostream>
#include<vector>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int stu_cnt, compare_cnt; std::cin >> stu_cnt >> compare_cnt;
	std::vector<std::vector<int>> requires_vec(stu_cnt + 1);
	std::vector<bool> in_formation(stu_cnt + 1, false);
	while (compare_cnt--) {
		int front, back; std::cin >> front >> back;
		requires_vec[back].push_back(front);
	}
	int students_cnt_in_formation = 0;
	while (students_cnt_in_formation != stu_cnt) {
		for (int i = 1; i < stu_cnt + 1; i++) {
			if (in_formation[i] == false) {
				bool get_in_the_formation = true;
				for (int required : requires_vec[i]) {
					if (in_formation[required] == false) {
						get_in_the_formation = false;
						break;
					}
				}
				if (get_in_the_formation == true) {
					students_cnt_in_formation++;
					in_formation[i] = true;
					std::cout << i << ' ';
				}
			}
		}
	}
	return 0;
}