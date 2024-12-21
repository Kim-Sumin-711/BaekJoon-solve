#include<iostream>
#include<string>

int get_score(const std::string& str) {
	int score = 0, O_stack = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'O')
			score += 1 + O_stack++;
		else
			O_stack = 0;
	}
	return score;
}

int main(void) {
	std::string str;
	int test_case = 0;
	std::cin >> test_case;
	while (test_case--) {
		std::cin >> str;
		std::cout << get_score(str) << "\n";
	}
	
	return 0;
}