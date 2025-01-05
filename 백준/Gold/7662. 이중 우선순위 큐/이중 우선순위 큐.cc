#include<iostream>
#include<set>
#include<algorithm>

void sol(void) {
	std::multiset<int> num_mulset;
	char oper;
	int oper_cnt,oper_num;
	std::cin >> oper_cnt;
	while (oper_cnt--) {
		std::cin >> oper >> oper_num;
		if (oper == 'I') {
			num_mulset.insert(oper_num);
		}
		else {
			if (num_mulset.size() != 0) {
				if (oper_num == 1)
					num_mulset.erase(--num_mulset.end());
					
				else
					num_mulset.erase(num_mulset.begin());
					
					
			}
		}
	}
	if (num_mulset.size() == 0)
		std::cout << "EMPTY\n";
	else
		std::cout << *(std::max_element(num_mulset.begin(), num_mulset.end())) << " " << *(std::min_element(num_mulset.begin(), num_mulset.end())) << "\n";
}

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int test;
	std::cin >> test;
	while (test--) {
		sol();
	}
	return 0;
}