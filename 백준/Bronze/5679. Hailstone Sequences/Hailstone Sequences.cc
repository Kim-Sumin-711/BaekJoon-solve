#include<iostream>

int get_next_num(const int& h) {
	if (h % 2 != 0) return 3 * h + 1;
	else return h / 2;
}

int main(void) {
	int h;
	std::cin >> h;
	while (h != 0) {
		int max_num = h;
		while (h != 1) {
			h = get_next_num(h);
			if (max_num < h) max_num = h;
		}
		std::cout << max_num << "\n";
		std::cin >> h;
	}
	return 0;
}