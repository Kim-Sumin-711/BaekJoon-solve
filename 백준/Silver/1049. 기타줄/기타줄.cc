#include<iostream>
int main(void) {
	int broken_line_cnt, brand_cnt; std::cin >> broken_line_cnt >> brand_cnt;
	int minimal_cost = 2100000000, 
		minimal_cost_for_six_package = 21000000, 
		minimal_cost_for_one_line = 2100000000;
	while (brand_cnt--) {
		int cost_for_six_package, cost_for_one_line; std::cin >> cost_for_six_package >> cost_for_one_line;
		if (minimal_cost_for_six_package > cost_for_six_package) minimal_cost_for_six_package = cost_for_six_package;
		if (minimal_cost_for_one_line > cost_for_one_line) minimal_cost_for_one_line = cost_for_one_line;
	}
	if (minimal_cost_for_six_package < minimal_cost_for_one_line * 6) {
		minimal_cost = (broken_line_cnt / 6) * minimal_cost_for_six_package;
		if (minimal_cost_for_six_package > minimal_cost_for_one_line * (broken_line_cnt % 6))
			minimal_cost += minimal_cost_for_one_line * (broken_line_cnt % 6);
		else minimal_cost += minimal_cost_for_six_package;
	}
	else minimal_cost = broken_line_cnt * minimal_cost_for_one_line;
	std::cout << minimal_cost;
	return 0;
}