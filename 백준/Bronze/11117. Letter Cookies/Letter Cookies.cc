#include<iostream>
#include<unordered_map>
#include<string>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int test;
	std::cin >> test;
	while (test--) {
		std::string str;
		std::cin >> str;
		std::unordered_map<char, int> cookie_box;
		for (auto iter = str.begin(); iter != str.end(); iter++) {
			if (cookie_box.find(*iter) != cookie_box.end())
				cookie_box[*iter] += 1;
			else
				cookie_box[*iter] = 1;
		}

		int words_cnt;
		std::cin >> words_cnt;
		while (words_cnt--) {
			std::string word;
			std::cin >> word;
			std::unordered_map<char, int> word_map;
			for (auto iter = word.begin(); iter != word.end(); iter++) {
				if (word_map.find(*iter) != word_map.end())
					word_map[*iter] += 1;
				else
					word_map[*iter] = 1;
			}
			bool possible = true;
			for (auto iter = word_map.begin(); iter != word_map.end(); iter++) {
				if (cookie_box.find(iter->first) == cookie_box.end()) {
					possible = false;
					break;
				}
				else {
					if (cookie_box[iter->first] < iter->second) {
						possible = false;
						break;
					}
				}
			}
			if (possible)
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}
	return 0;
}