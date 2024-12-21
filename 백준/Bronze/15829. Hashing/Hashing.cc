#include<iostream>
#include<string>

int get_hash(const int& len, const std::string& str) {
	long int tmp;
	long int res=0;
	for (int i = 0; i < str.size(); i++) {
		tmp = (int)str[i] - 96;
		for (int j = i; j > 0; j--) {
			tmp *= 31;
			tmp %= 1234567891;
		}
		res += tmp;
		res %= 1234567891;
	}
	return res;
}

int main(void) {
	int len;
	std::string target;
	std::cin >> len >> target;
	std::cout << get_hash(len, target);
	return 0;
}