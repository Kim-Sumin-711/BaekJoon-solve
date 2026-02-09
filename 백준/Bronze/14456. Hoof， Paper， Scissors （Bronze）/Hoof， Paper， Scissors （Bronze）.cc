#include<iostream>
#include<cmath>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int rounds; std::cin >> rounds;
	int win_cnt1=0, win_cnt2=0, win_cnt3=0;
	while (rounds--) {
		short c1, c2;
		std::cin >> c1 >> c2;
		if (c1 == c2) continue;
		else {
			if (c1 == 1 && c2 == 3)win_cnt1++;
			else if (c1 == 1 && c2 == 2)win_cnt2++;
			else if (c1 == 2 && c2 == 1)win_cnt1++;
			else if (c1 == 2 && c2 == 3)win_cnt2++;
			else if (c1 == 3 && c2 == 1)win_cnt2++;
			else if (c1 == 3 && c2 == 2) win_cnt1++;
		}
	}
	std::cout << std::max(win_cnt1, win_cnt2);
	return 0;
}