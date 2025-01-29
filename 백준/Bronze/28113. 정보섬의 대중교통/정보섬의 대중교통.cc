#include<iostream>
int main(void) {
	int N, A, B;
	std::cin >> N >> A >> B;
	if (B >= N) {
		if (B < A)
			std::cout << "Subway";
		else if (B > A)
			std::cout << "Bus";
		else
			std::cout << "Anything";
	}
	else {
		std::cout << "Subway";
	}
	return 0;
}