#include<iostream>
#include<vector>

int sol(const std::vector<int>& cards, const int& sum_target) {
	int res=0;
	int tmp;
	for (int fir = 0; fir < cards.size() - 2; fir++) {
		for (int sec = fir + 1; sec < cards.size() - 1; sec++) {
			for (int thr = sec + 1; thr < cards.size(); thr++) {
				tmp = cards[fir] + cards[sec] + cards[thr];
				if (res < tmp && tmp <= sum_target)
					res = tmp;
			}
		}
	}
	return res;
}

int main(void) {
	int card_cnt, sum_target;
	std::cin >> card_cnt >> sum_target;
	std::vector<int> cards(card_cnt);
	for (int& elem : cards) {
		std::cin >> elem;
	}
	std::cout << sol(cards, sum_target);

	return 0;
}