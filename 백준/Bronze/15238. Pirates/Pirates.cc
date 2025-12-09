#include<iostream>
#include<string>
#include<vector>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int len; std::cin >> len;
	std::string text;
	std::cin >> text;
	std::vector<int> alpha_cnt(26, 0);
	//a --> 97
	for (const char& ch : text) {
		alpha_cnt[(int)ch - 97]++;
	}

	int max_index = 0, max_cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha_cnt[i] > max_cnt) {
			max_index = i;
			max_cnt = alpha_cnt[i];
		}
	}
	std::cout << (char)(max_index + 97) << ' ' << max_cnt;
	return 0;
}