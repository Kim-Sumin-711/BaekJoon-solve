#include<iostream>
#include<string>
#include<vector>
std::vector<char> Caesar_transfer(const std::string& str) {
	std::vector<char> result;
	for (int i = 0; i < str.size(); i++) {
		if ((int)str[i] <= 67) {
			result.push_back((char)(str[i] + 23));
		}
		else {
			result.push_back((char)(str[i] - 3));
		}
	}
	return result;
}

int main(void) {
	std::string str;
	std::cin >> str;
	for (const char& elem : Caesar_transfer(str)) {
		std::cout << elem;
	}

	return 0;
}