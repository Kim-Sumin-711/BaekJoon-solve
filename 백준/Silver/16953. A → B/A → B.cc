#include<iostream>
#include<queue>
#include<vector>
#include<unordered_set>

void set_next_num_in_queue(std::queue<long long>& qu, const long long& now_num, std::unordered_set<long long>& visit, const long long& goal) {
	long long next1 = 2 * now_num, next2 = now_num * 10 + 1;
	if (next1 <= goal && visit.find(next1) == visit.end()) {
		qu.push(next1);
		visit.insert(next1);
	}
	if (next2 <= goal && visit.find(next2) == visit.end()) {
		qu.push(next2);
		visit.insert(next2);
	}
}

long long get_min_transfer_cnt(const long long& base, const long long& goal) {
	std::queue<long long> num_qu;
	std::unordered_set<long long> visit;
	long long now = 0, size = 0;
	long long transfer_cnt = 1;
	num_qu.push(base);
	visit.insert(base);
	while (num_qu.size() != 0) {
		size = num_qu.size();
		while (size--) {
			now = num_qu.front();
			num_qu.pop();
			if (now == goal)
				return transfer_cnt;
			set_next_num_in_queue(num_qu, now, visit, goal);
		}
		transfer_cnt++;
	}
	return -1;
}

int main(void) {
	long long base, goal;
	std::cin >> base >> goal;
	std::cout << get_min_transfer_cnt(base, goal);
	return 0;
}