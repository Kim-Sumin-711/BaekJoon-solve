#include<iostream>
#include<vector>
#include<string>
int main(void) {
	int test, target_cnt = 0;
	
	std::string str;
	std::cin >> test;
	while (test--) {
		bool this_is_target = true;
		std::vector<bool> found_char_vec(29,false);
		std::cin >> str;
		for (int i = 0; i < str.size();i++) {
			if (!found_char_vec[str[i] - 97])
				found_char_vec[str[i] - 97] = true;
			else {
				if (str[i - 1] != str[i]) {
					this_is_target = false;
					break;
				}
			}
		}
		if (this_is_target)
			target_cnt++;
	}
	std::cout << target_cnt;
	return 0;
}
