#include<iostream>
#include<cmath>
int main(void) {
	int sang, joong, ha, cola, soda;
	std::cin >> sang >> joong >> ha >> cola >> soda;
	int drink = std::min(cola, soda), set1 = sang + drink - 50, set2 = joong + drink - 50, set3 = ha + drink - 50;
	std::cout << std::min(std::min(set1, set2), set3);
	return 0;
}