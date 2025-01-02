#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cout << std::fixed;
	std::cout.precision(6);
	int num_cnt;
	std::cin >> num_cnt;
	std::vector<double> num_vec(num_cnt);
	std::deque<double> num_deque;
	for (int i = 0; i < num_cnt; i++)
		std::cin >> num_vec[i];

	std::sort(num_vec.begin(),num_vec.end());
	for (int i = 0; i < num_cnt;i++) {
		num_deque.push_back(num_vec[i]);
	}
	num_vec.clear();
	for (int i = 0; i < num_cnt - 1; i++) {
		double tmp1 = num_deque.front();
		num_deque.pop_front();
		double tmp2 = num_deque.front();
		num_deque.pop_front();
		num_deque.push_front((tmp1 + tmp2) / 2);
	}
	std::cout << num_deque.front();

	return 0;
}