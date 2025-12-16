#include<iostream>
#include<string>
int main(void) {
	std::string text;
	std::cin >> text;
	int vowels_cnt = 0, y_cnt = 0;
	for (char ch : text) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') vowels_cnt++;
		else if (ch == 'y') y_cnt++;
	}
	std::cout << vowels_cnt << ' ' << vowels_cnt+y_cnt;
	return 0;
}