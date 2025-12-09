#include<iostream>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int N, X, change_cnt;
	std::cin >> N >> X >> change_cnt;
	while (change_cnt--) {
		int swap1, swap2;
		std::cin >> swap1 >> swap2;
		if (swap1 == X) X = swap2;
		else if (swap2 == X) X = swap1;
	}
	std::cout << X;
	return 0;
}