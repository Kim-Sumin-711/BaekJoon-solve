#include<iostream>
#include<vector>
int main(void) {
	int stick_cnt; std::cin >> stick_cnt;
	std::vector<int> sticks(stick_cnt);
	for (int& stick : sticks) {
		std::cin >> stick;
	}
	int height = 0, visible_cnt = 0;
	for (int i = stick_cnt - 1; i > -1; i--) {
		if (height < sticks[i]) {
			height = sticks[i];
			visible_cnt++;
		}
	}
	std::cout << visible_cnt;
	return 0;
}