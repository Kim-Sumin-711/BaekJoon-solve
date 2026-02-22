#include<iostream>
#include<string>
int main(void) {
	std::string txt; std::cin >> txt;
	for (char ch : txt) {
		if (ch >= 'a') {
			ch -= 32;
			std::cout << ch;
		}
		else {
			ch += 32;
			std::cout << ch;
		}
	}
	return 0;
}