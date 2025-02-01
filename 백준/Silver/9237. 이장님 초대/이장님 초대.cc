#include<iostream>
#include<vector>
#include<algorithm>
void set_tree_days(std::vector<int>& tree_days) {
	for (int& day : tree_days)
		std::cin >> day;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int tree_cnt;
	std::cin >> tree_cnt;
	std::vector<int> tree_days(tree_cnt);

	set_tree_days(tree_days);
	std::sort(tree_days.begin(), tree_days.end(), [] (int a, int b) {return a > b; });

	int plant_days = tree_days.size(); //나무를 심는데만 걸리는 시간
	for (int& elem : tree_days) {
		plant_days--;
		elem -= plant_days;
	}

	std::cout << tree_days.size() + *std::max_element(tree_days.begin(), tree_days.end())+1;

	return 0;
}