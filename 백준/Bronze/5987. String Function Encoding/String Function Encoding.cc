#include<iostream>
#include<string>
int main(void) {
	int test, n, loop;
	std::string str;
	std::cin >> test;
	while (test--) {
		std::cin >> n >> loop >> str;
		while (loop--) {
			str = str.substr(n, str.size() - n) + str;
		}
		std::cout << str << "\n";
	}
	return 0;
}