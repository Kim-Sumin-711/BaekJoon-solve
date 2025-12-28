#include<iostream>
//I think the answers have a regularity.
//I guess (+2 +2 -1) (+2 +2 -1) is the best moving way for this problem.
//+2 is to move 2 right, -1 is to move 1 left.
//there are three movement.
//type A : +2 +2 -1 +2 +2 -1... +2 +2 -1 --> N%3 ==0
//type B : +2 +2 -1 +2 +2 -1 ... +2 -1 --> 2
//type C : +2 +2 -1 +2 +2 -1 ... +1 --> 1

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int house_cnt;
	std::cin >> house_cnt;
	if (house_cnt % 3 == 0) {
		std::cout << house_cnt << "\n";
		std::cout << 1 << ' ';
		int loop = house_cnt / 3 - 1;
		int now = 1;
		while (loop--) {
			now += 2;
			std::cout << now << ' ';
			now += 2;
			std::cout << now << ' ';
			now--;
			std::cout << now << ' ';
		}
		std::cout << house_cnt << ' ';
		std::cout << 2 << ' ' << 1;
	}
	else if (house_cnt % 3 == 1) {
		std::cout << house_cnt << "\n";
		int now = 1;
		std::cout << now << ' ';
		now++;
		std::cout << now << ' ';
		now += 2;
		std::cout << now << ' ';
		now--;
		std::cout << now << ' ';
		int loop = house_cnt / 3-1;
		while (loop--) {
			now += 2;
			std::cout << now << ' ';
			now += 2;
			std::cout << now << ' ';
			now--;
			std::cout << now << ' ';
		}
		std::cout << 1;
	}
	else {
		std::cout << house_cnt << "\n";
		int now = 1;
		std::cout << now << ' ';
		now++;
		std::cout << now << ' ';
		now += 2;
		std::cout << now << ' ';
		now--;
		std::cout << now << ' ';
		int loop = house_cnt / 3-1;
		while (loop--) {
			now += 2;
			std::cout << now << ' ';
			now += 2;
			std::cout << now << ' ';
			now--;
			std::cout << now << ' ';
		}
		std::cout << now + 2 << ' ' << 1;
	}
	
	return 0;
}