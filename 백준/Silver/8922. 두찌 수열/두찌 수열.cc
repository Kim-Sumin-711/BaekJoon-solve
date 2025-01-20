#include<iostream>
#include<vector>
#include<cmath>

void set_tuple(std::vector<short>& tuple) {
	for (short& elem : tuple) {
		std::cin >> elem;
	}
}

void move_tuple(std::vector<short>& tuple) {
	short tmp = tuple[0];
	for (int i = 0; i < tuple.size() - 1; i++) {
		tuple[i] = std::abs(tuple[i + 1]-tuple[i]);
	}
	tuple[tuple.size() - 1] = std::abs(tuple[tuple.size() - 1] - tmp);
}

bool is_zero_tuple(const std::vector<short>& tuple) {
	for (const short& elem : tuple) {
		if (elem != 0)
			return false;
	}
	return true;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int test_case;
	int tuple_size;
	std::cin >> test_case;
	while (test_case--) {
		int oper_cnt = 0;
		std::cin >> tuple_size;
		std::vector<short> tuple(tuple_size);
		set_tuple(tuple);
		while (oper_cnt < 1000) {
			move_tuple(tuple);
			if (is_zero_tuple(tuple)) {
				std::cout << "ZERO\n";
				break;
			}
			oper_cnt++;
		}
		if (oper_cnt == 1000) {
			std::cout << "LOOP\n";
		}
	}
	return 0;
}