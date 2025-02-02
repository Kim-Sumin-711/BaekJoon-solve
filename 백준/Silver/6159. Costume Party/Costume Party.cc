#include<iostream>
#include<vector>

void set_cows(std::vector<int>& cows) {
	for (int i = 1; i < cows.size(); i++)
		std::cin >> cows[i];
}

int get_fits_pair_of_cows_cnt(const std::vector<int>& cows, const int& costume_size) {
	int cow_pair_cnt = 0;
	for (auto iter1 = cows.begin()+1; iter1 != cows.end(); iter1++) {
		for (auto iter2 = iter1 + 1; iter2 != cows.end(); iter2++) {
			if ((*iter1) + (*iter2) <= costume_size)
				cow_pair_cnt++;
		}
	}
	return cow_pair_cnt;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int cow_cnt, costume_size;
	std::cin >> cow_cnt >> costume_size;
	std::vector<int> cows(cow_cnt + 1);
	set_cows(cows);
	std::cout << get_fits_pair_of_cows_cnt(cows, costume_size);
	return 0;
}