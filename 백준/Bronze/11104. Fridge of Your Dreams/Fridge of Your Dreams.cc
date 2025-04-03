#include<iostream>
#include<string>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int test;
	std::cin >> test;
	while (test--) {
		int two = 1, result=0;
		std::string barcode;
		std::cin >> barcode;
		for (auto iter = barcode.end() - 1; iter != barcode.begin(); iter--) {
			if (*iter == '1')	result += two;
			two *= 2;
		}
		if (barcode[0] == '1') {
			result += two;
		}
		std::cout << result << "\n";
	}
	return 0;
}