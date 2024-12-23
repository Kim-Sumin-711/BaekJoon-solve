#include<iostream>

int gcd(const int&a, const int& b){
	if (a % b != 0) {
		return gcd(b, a % b);
	}
	else {
		return b;
	}
}
int lcm(const int& a, const int& b) {
	return a * b / gcd(a, b);
}

int get_stop_cnt(const int& period, const int& totalD) {
	if (totalD % period) {
		return totalD / period;
	}
	else {
		return (totalD / period) - 1;
	}
}

int main(void) {
	int t;
	std::cin >> t;
	while(t--) {
		int totalD, refuelD, foodD;
		std::cin >> totalD >> refuelD >> foodD;
		std::cout << totalD << " " << refuelD << " " << foodD<< "\n";
		int stopCnt = get_stop_cnt(refuelD, totalD) + get_stop_cnt(foodD, totalD) - get_stop_cnt(lcm(refuelD, foodD), totalD);
		std::cout << stopCnt << "\n";
	}
	return 0;
}