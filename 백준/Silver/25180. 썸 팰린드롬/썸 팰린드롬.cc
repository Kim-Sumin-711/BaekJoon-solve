#include<iostream>
int main(void) {
	int target;
	std::cin >> target;
	if (target < 10)
		std::cout << 1;
	else {
		int solution = 0;
		if (target % 2) {
			target -= 9;
			solution++;
		}
		while (target / 2 >= 9) {
			target -= 18;
			solution += 2;
		}
		if (target != 0) {
			if (solution % 2)
				solution += 2;
			else if (target < 10)
				solution += 1;
			else
				solution += 2;
		}
			
		std::cout << solution;
	}
	return 0;
}