#include<iostream>
#include<queue>
#include<vector>

void set_DSLR(const int& now, int& D, int& S, int& L, int& R) {
	D = now * 2;
	if (D > 9999)
		D -= 10000;
	if(now == 0)
		S = 9999;
	else
		S = now - 1;

	L = (now % 1000) * 10 + now / 1000;
	R = now / 10 + (now % 10) * 1000;
	
}

void set_next_num_in_queue(std::queue<int>& qu, const int& now, std::vector<bool>& visit, std::vector<std::pair<int,char>>& dp) {
	int D, S, L, R;
	set_DSLR(now, D, S, L, R);
	if (!visit[D]) {
		visit[D] = true;
		qu.push(D);
		dp[D] = std::make_pair(now, 'D');
	}
	if (!visit[S]) {
		visit[S] = true;
		qu.push(S);
		dp[S] = std::make_pair(now, 'S');
	}
	if (!visit[L]) {
		visit[L] = true;
		qu.push(L);
		dp[L] = std::make_pair(now, 'L');
	}
	if (!visit[R]) {
		visit[R] = true;
		qu.push(R);
		dp[R] = std::make_pair(now, 'R');
	}
}

void print_min_size_oper(const int& base, const int& target) {
	std::queue<int> qu;
	std::vector<bool> visit(10000);
	//전 숫자, 오퍼레이터 문자.
	std::vector<std::pair<int, char>> dp(10000);
	qu.push(base);
	visit[base] = true;
	while (qu.size() != 0) {
		int now = qu.front();
		qu.pop();
		if (now == target)
			break;
		set_next_num_in_queue(qu, now,visit, dp);
	}
	std::vector<char> res;
	res.push_back(dp[target].second);
	int now = target;
	while (true) {
		now = dp[now].first;
		if (now == base)
			break;
		res.push_back(dp[now].second);
	}
	for (int i = res.size() - 1; i >= 0; i--) {
		std::cout << res[i];
	}
	std::cout << "\n";
}

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int test,base,target;
	std::cin >> test;
	while (test--) {
		std::cin >> base >> target;
		print_min_size_oper(base, target);
	}
	return 0;
}