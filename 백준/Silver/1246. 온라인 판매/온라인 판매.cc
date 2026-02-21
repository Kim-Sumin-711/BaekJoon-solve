#include<iostream>
#include<vector>
#include<algorithm>
int main(void) {
	int egg_cnt, client_cnt; std::cin >> egg_cnt >> client_cnt;
	std::vector<int> pi(client_cnt);
	for (int& price : pi) {
		std::cin >> price;
	}
	std::sort(pi.begin(), pi.end());
	int egg_price = 0, revenue = 0;
	for (int i = 0; i < pi.size(); i++) {
		if (egg_cnt >= client_cnt - i) {
			if (revenue < pi[i] * (client_cnt - i)) {
				revenue = pi[i] * (client_cnt - i);
				egg_price = pi[i];
			}
		}
		else {
			if (revenue < pi[i] * egg_cnt) {
				revenue = pi[i] * egg_cnt;
				egg_price = pi[i];
			}
		}
	}
	std::cout << egg_price << ' ' << revenue;
	return 0;
}