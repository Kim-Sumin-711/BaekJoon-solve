#include<iostream>
#include<string>
int main(void) {
	int num;
	std::string str;
	std::cin >> num;
	std::cin >> str;
	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += (int)str[i]-48;
	}
	std::cout << sum;
	return 0;
}