#include<iostream>
#include<string>
int main(void) {
	std::string ah1, ah2; std::cin >> ah1 >> ah2;
	if (ah1.size() >= ah2.size()) std::cout << "go";
	else std::cout << "no";
	
	return 0;
}