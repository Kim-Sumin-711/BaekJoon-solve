#include<iostream>
#include<string>

bool lucky_str(const std::string& str) {
	int chain = 1;
	//알파벳 대문자만 들어오므로 a같은 경우도 처리가능.
	for (int i = 1; i < str.size(); i++) {
		if (std::abs((int)str[i - 1] - (int)str[i]) == 1)
			chain++;
		else
			chain = 1;
		if (chain == 5)
			return true;
	}
	return false;
}

int main(void) {
	int N;
	std::cin >> N;
	std::string str;
	std::cin >> str;
	if (lucky_str(str))
		std::cout << "YES";
	else
		std::cout << "NO";
	return 0;
}