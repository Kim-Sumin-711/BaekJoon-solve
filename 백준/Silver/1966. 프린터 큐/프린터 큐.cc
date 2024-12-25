#include<iostream>
#include<queue>
#include<vector>

void set_queue_and_db_vec(std::queue<std::vector<short int>>& qu, std::vector<short int>& db,const short int&doc_cnt, const short int& target) {
	short int important;
	for (short int i = 0; i < doc_cnt; i++) {
		std::cin >> important;
		if (i == target)
			qu.push({ 1,important });
		else
			qu.push({ 0,important });
		db[important] += 1;
	}
}


bool most_important(const short int& important, const std::vector<short int>& db) {
	for (short int i = important + 1; i < 10; i++) {
		if (db[i] > 0)
			return false;
	}
	return true;
}

int get_print_number(std::queue<std::vector<short int>>& qu, std::vector<short int>& db) {
	int res = 0;
	std::vector<short int> tmp;
	while (true) {
		tmp = qu.front();
		if (most_important(tmp[1], db)) {
			res++;
			if (tmp[0] == 1)
				return res;
			else {
				qu.pop();
				db[tmp[1]] -= 1;
			}

		}
		else {
			qu.pop();
			qu.push(tmp);
		}
	}
	return res;
}

void sol(void) {
	std::queue<std::vector<short int>> printer;
	std::vector<short int>important_db = { 0,0,0,0,0,0,0,0,0,0 };
	short int doc_cnt, target;
	std::cin >> doc_cnt >> target;
	set_queue_and_db_vec(printer, important_db,doc_cnt,target);
	std::cout << get_print_number(printer, important_db) << "\n";
}


int main(void) {
	int test_case;
	std::cin >> test_case;
	while (test_case--) {
		sol();
	}
	return 0;
}