#include<iostream>
int main(void) {
	int aattack, ahealth, battack, bhealth;
	std::cin >> aattack >> ahealth >> battack >> bhealth;
	while (ahealth > 0 && bhealth > 0) {
		ahealth -= battack;
		bhealth -= aattack;
	}
	if (ahealth > 0)
		std::cout << "PLAYER A";
	else if (bhealth > 0)
		std::cout << "PLAYER B";
	else 
		std::cout << "DRAW";
	return 0;
}