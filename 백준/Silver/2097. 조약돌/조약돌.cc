#include<iostream>
#include<cmath>
int main(void) {
	long long pebbles_cnt,square_of_pebbles_cnt;
	std::cin >> pebbles_cnt;
	if (pebbles_cnt == 1 || pebbles_cnt == 2)
		std::cout << 4;
	else {
		long long k = 1;
		while (k++) {
			long long square = k * k;
			if (square > pebbles_cnt) {
				k--;
				break;
			}
			else if (square == pebbles_cnt) {
				std::cout << (k - 1) * 4;
				return 0;
			}
		}
		if (k * (k + 1) >= pebbles_cnt)
			std::cout << (2 * k - 1) * 2;
		else
			std::cout << k * 4;
			
	}
	return 0;
}