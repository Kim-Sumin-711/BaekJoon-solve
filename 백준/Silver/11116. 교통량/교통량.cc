#include<iostream>
#include<unordered_set>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int test;
	std::cin >> test;
	while (test--) {
		int record_cnt, left_car=0;
		std::cin >> record_cnt;
		std::unordered_set<int> leftbox, rightbox;
		for (int i = 0; i < record_cnt; i++) {
			int temp; std::cin >> temp;
			leftbox.insert(temp);
		}
		for (int i = 0; i < record_cnt; i++) {
			int temp; std::cin >> temp;
			rightbox.insert(temp);
		}
		for (auto iter = leftbox.begin(); iter != leftbox.end();) {
			if (leftbox.find((*iter) + 500) != leftbox.end()) {
				if (rightbox.find((*iter) + 1000) != rightbox.end()) {
					if (rightbox.find((*iter) + 1500) != rightbox.end()) {
						left_car++;
						leftbox.erase(*iter + 500);
						rightbox.erase(*iter + 1000);
						rightbox.erase(*iter + 1500);
						//이터 erase하면 다음 iter반환함.
						iter = leftbox.erase(iter);
					}
					else iter++;
				}
				else iter++;
			}
			else iter++;
		}
		std::cout << left_car << std::endl;
	}
	return 0;
}