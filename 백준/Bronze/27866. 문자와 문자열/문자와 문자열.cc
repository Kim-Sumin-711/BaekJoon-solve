#include<iostream>
#include<string>
int main(void) {
	std::string str;
	std::cin >> str;
	int i;
	std::cin >> i;
	std::cout << str[i-1];
	return 0;
}