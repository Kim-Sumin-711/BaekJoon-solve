#include<iostream>
#include<string>
#include<cctype>
int main(void) {
	std::string str;
	bool punc = false, with_white_or_bracket = false;
	while (true) {
		std::getline(std::cin, str);
		if (str == "")
			break;
		for (char& c : str) {
			if (c == '.' || c == '?' || c == '!') {
				punc = true;
			}
			else if (c != ' ' && c != '(' && c != ')') {
				if (!std::isdigit(c)) {
					if (punc) {
						c = std::toupper(c);
						punc = false;

					}
					else {
						c = std::tolower(c);
					}
				}
				else
					punc = false;
			}
			
		}
		std::cout << str << "\n";
	}
	return 0;
}