#include<iostream>
#include<string>
#include<deque>

void handle_bomb(std::deque<char>& result, const std::string& bomb) {
	for (int i = bomb.size()-1; i >-1; i--) {
		if (result.back() == bomb[i]) result.pop_back();

		else {
			for (int j = i + 1; j < bomb.size(); j++)
				result.push_back(bomb[j]);
			break;
		}
	}
}

void print_result(std::deque<char>& result) {
	if (result.empty()) std::cout << "FRULA";
	else {
		while (!result.empty()) {
			std::cout << result.front();
			result.pop_front();
		}
	}
}

void sol(const std::string& str, const std::string& bomb) {
	std::deque<char> result;
	int a_last_char_of_bomb = bomb.size() - 1;
	for (int cursor = 0; cursor < str.size(); cursor++) {
		result.push_back(str[cursor]);
		if (str[cursor] == bomb[a_last_char_of_bomb]) {
			if (result.size() >= bomb.size()) handle_bomb(result, bomb);
		}
	}
	print_result(result);
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::string str, bomb;
	std::cin >> str >> bomb;
	sol(str, bomb);
	return 0;
}