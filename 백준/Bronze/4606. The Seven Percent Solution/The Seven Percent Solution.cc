#include<iostream>
#include<string>
int main(void) {
	std::string str;
	std::getline(std::cin, str);
	while (str != "#") {
		for (const char ch : str) {
			switch (ch) {
			case ' ':
				std::cout << "%20";
				break;
			case '!':
				std::cout << "%21";
				break;
			case '$':
				std::cout << "%24";
				break;
			case '%':
				std::cout << "%25";
				break;
			case '(':
				std::cout << "%28";
				break;
			case ')':
				std::cout << "%29";
				break;
			case '*':
				std::cout << "%2a";
				break;
			default:
				std::cout << ch;
				break;
			}
		}
		std::cout << "\n";
		std::getline(std::cin, str);
	}

	return 0;
}