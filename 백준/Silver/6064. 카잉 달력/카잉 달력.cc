#include<iostream>

int gcd(const int& a, const int& b) {
	if (a % b == 0)
		return b;
	else
		return gcd(b, a%b);
}

long lcm(const int& a, const int& b) {
	return a * b / gcd(a, b);
}

int transfer(int y, int N) {
	if (y == N)
		return 0;
	else
		return y;
}

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int test;
	std::cin >> test;
	while (test--) {
		int M, N, x, y;
		long res = 1;
		std::cin >> M >> N >> x >> y;
		if (1 == x && 1 == y) {
			std::cout << 1 << "\n";
			continue;
		}
		if (M > N) {
			std::swap(x, y);
			std::swap(M, N);
		}
		bool find = false;
		int loop = 0;
		long LCM = lcm(M, N);
		long nowx = 0;
		while (LCM >= nowx) {
			if ((nowx + x) % N == transfer(y,N)) {
				find = true;
				res = loop * M + x;
				break;
			}
			nowx += M;
			loop++;
		}
		if (!find)
			std::cout << -1 << "\n";
		else
			std::cout << res << "\n";
	}
	return 0;
}