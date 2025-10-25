#include<iostream>
int main(void) {
	std::cin.tie(0); std::cout.tie(0);
	std::cout << std::fixed;
	std::cout.precision(2);
	double puppy_cnt, food_per_pup, price_per_pound;
	int loop;
	
	std::cin >> loop;
	while (loop--) {
		double required_money = 0;
		std::cin >> puppy_cnt >> food_per_pup >> price_per_pound;
		required_money = puppy_cnt * food_per_pup * price_per_pound;
		std::cout << '$' << required_money << "\n";
	}
	return 0;
}