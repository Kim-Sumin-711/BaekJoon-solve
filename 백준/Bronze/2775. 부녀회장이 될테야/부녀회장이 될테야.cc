#include<iostream>
#include<vector>
int main(void) {
	int test_case,floor, ho;
	std::vector<int> now;
	std::cin >> test_case;
	while (test_case--) {
		int now_floor = 0;
		now.clear();
		std::cin >> floor >> ho;
		if (floor == 0) {
			std::cout << ho << "\n";
			continue;
		}
		while (now_floor < floor) {
			if (now_floor == 0) {
				for (int i = 0; i < ho; i++) {
					now.push_back(i + 1);
				}
			}
			if (ho == 1) {
				break;
			}
			for (int i = 1; i < ho; i ++) {
				now[i] = now[i - 1] + now[i];
			}
			now_floor++;
		}
		std::cout << now[ho - 1] << "\n";
	}
	return 0;
}