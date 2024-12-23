#include<iostream>
int main(void) {
	int a, b,goal, day=0, now = 0;
	std::cin >> a >> b >> goal;
	while (true) {
		now += a;
		day++;
		if (now >= goal) {
			break;
		}
		now -= b;
	}
	std::cout << day;
	return 0;
}