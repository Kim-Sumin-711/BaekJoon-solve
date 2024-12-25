#include<iostream>
#include<queue>
#include<vector>

void set_queue(std::queue<int>& qu, const int& n) {
	for (int i = 1; i < n + 1; i++)
		qu.push(i);
}

void del_person(std::queue<int>& qu, const int& k, std::vector<int>& res) {
	if (qu.size() >1) {
		for (int i = 0; i < k-1; i++) {
			int tmp = qu.front();
			qu.pop();
			qu.push(tmp);
		}
		res.push_back(qu.front());
		qu.pop();
	}
	else {
		res.push_back(qu.front());
		qu.pop();
	}
}

void print_res_vec(const std::vector<int>& res) {
	std::cout << "<" << res[0];
	for (int i = 1; i < res.size(); i++) {
		std::cout << ", " << res[i];
	}
	std::cout << ">";
}

void sol(const int& n, const int& k) {
	std::queue<int>people_queue;
	std::vector<int> res;
	set_queue(people_queue, n);
	for (int i = 0; i < n; i++) {
		del_person(people_queue, k, res);
	}
	print_res_vec(res);
}

int main(void) {
	int n, k;
	std::cin >> n >> k;
	sol(n, k);
	return 0;
}