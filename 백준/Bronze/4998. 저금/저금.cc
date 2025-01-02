#include<iostream>
int main(void) {
	double N=-1, B=-1, M=-1;
	std::cin >> N >> B >> M;
	while (N!=-1) {
		int year = 0;
		while (N <= M) {
			N *= (1 + B * 0.01);
			year++;
		}
		std::cout << year << "\n";
		N = -1, B = -1, M = -1;
		std::cin >> N >> B >> M;
	}
	return 0;
}