#include<iostream>
int main(void) {
	int team_cnt, chair_cnt, price_of_chair, shipping_cost;
	std::cin >> team_cnt >> chair_cnt >> price_of_chair >> shipping_cost;
	int needed_chair = 3 * team_cnt;
	if (chair_cnt >= needed_chair) std::cout << 0;
	else {
		needed_chair -= chair_cnt;
		std::cout << needed_chair * price_of_chair + shipping_cost;
	}
	return 0;
}