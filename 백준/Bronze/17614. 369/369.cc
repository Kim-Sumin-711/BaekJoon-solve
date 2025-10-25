#include<iostream>
#include<string>

int get_clap_cnt_for_a_text(std::string& s) {
	int claps = 0;
	for (char c : s) {
		if (c == '3' || c == '6' || c == '9') claps++;
	}
	return claps;
}
int main(void) {
	int num;
	std::cin >> num;
	int num2 = 3, claps_cnt = 0;
	while (num >= num2) {
		std::string temp = std::to_string(num2);
		claps_cnt += get_clap_cnt_for_a_text(temp);
		num2++;
	}
	std::cout << claps_cnt;
	return 0;
}