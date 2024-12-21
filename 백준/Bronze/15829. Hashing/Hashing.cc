#include<iostream>
#include<string>
#include<cmath>
int get_hash(const int& len, const std::string& str) {
	int r = 31, M = 1234567891;
	long int sum=0;
	for (int i = 0; i < len ; i++) {
		sum += ((int)str[i] - 96) * (long int)std::pow(r, i);
	}
	return sum % M;
}

int main(void) {
	int len;
	std::string target;
	std::cin >> len >> target;
	std::cout << get_hash(len, target);
	return 0;
}