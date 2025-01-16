#include<iostream>
int main(void) {
	int cook_cnt;
	std::cin >> cook_cnt;
	while (cook_cnt--) {
		int A, B, X;
		std::cin >> A >> B >> X;
		std::cout << A * (X - 1) + B << "\n";
	}
	
	return 0;
}