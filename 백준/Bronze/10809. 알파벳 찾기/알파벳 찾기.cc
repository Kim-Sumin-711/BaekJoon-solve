#include<iostream>
#include<vector>
#include<string>

void sol(const std::string& str) {
	std::vector<int>alpha_pos_vec(26,-1);
	int tmp = 0;
	for (int i = 0; i < str.size(); i++) {
		tmp = (int)str[i] - 97;
		if (alpha_pos_vec[tmp] == -1) {
			alpha_pos_vec[tmp] = i;
		}
	}
	for (const int& elem : alpha_pos_vec) {
		std::cout << elem << " ";
	}
}

int main(void) {
	std::string str;
	std::cin >> str;
	sol(str);
	return 0;
}