#include<iostream>
#include<vector>
int main(void) {
	int total_bus_cnt, goto_bus_cnt;
	std::cin >> total_bus_cnt >> goto_bus_cnt;
	std::vector<int> goto_bus_num(goto_bus_cnt);
	for (int& num : goto_bus_num) {
		std::cin >> num;
	}
	std::vector<std::vector<int>> transfer_fee(total_bus_cnt, std::vector<int>(total_bus_cnt));
	for (std::vector<int>& vec : transfer_fee) {
		for (int& elem : vec) {
			std::cin >> elem;
		}
	}

	int total_transfer_fee = 0;
	for (int i = 0; i < goto_bus_cnt - 1; i++) {
		total_transfer_fee += transfer_fee[goto_bus_num[i] - 1][goto_bus_num[i + 1] - 1];
	}
	std::cout << total_transfer_fee;
	return 0;
}