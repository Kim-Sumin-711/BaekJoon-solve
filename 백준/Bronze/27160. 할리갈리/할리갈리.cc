#include<iostream>
#include<vector>
#include<string>
int main(void) {
	int card_cnt; std::cin >> card_cnt;
	std::vector<int> fruits_cnt(4, 0);
	for (int i = 0; i < card_cnt; i++) {
		std::string fruit =""; std::cin >> fruit;
		int fruit_num = 0;
		if (fruit[0] == 'S') fruit_num = 0;
		else if (fruit[0] == 'B') fruit_num = 1;
		else if (fruit[0] == 'L') fruit_num = 2;
		else fruit_num = 3;

		int cnt; std::cin >> cnt;
		fruits_cnt[fruit_num] += cnt;
	}
	for (int fn = 0; fn < 4; fn++) {
		if (fruits_cnt[fn] == 5) {
			std::cout << "YES";
			return 0;
		}
	}
	std::cout << "NO";
	return 0;
}