#include<iostream>
#include<string>
#include<cctype>
int main(void) {
	std::string a, b, c;
	int i = 0;
	std::cin >> a >> b >> c;
	if (std::isdigit(a[0])) {
		i = std::stoi(a)+3;
	}
	else if (std::isdigit(b[0])) {
		i = std::stoi(b) + 2;
	}
	else if (std::isdigit(c[0])) {
		i = std::stoi(c)+1;
	}
	//일단 세개 다 문자열인거는 고려안하고 해봄.
	if (i % 3 == 0) {
		std::cout << "Fizz";
	}
	if (i % 5 == 0) {
		std::cout << "Buzz";
	}
	if (i % 3 != 0 && i % 5 != 0) {
		std::cout << i;
	}

	return 0;
}