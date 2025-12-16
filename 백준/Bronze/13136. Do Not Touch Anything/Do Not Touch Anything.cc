#include<iostream>
int main(void) {
	long long R, C, N;
	std::cin >> R >> C >> N;
	long long ans;
	if (R % N != 0) ans = R / N + 1;
	else ans = R / N;
	if (C % N != 0) ans *= C / N + 1;
	else ans *= C / N;
	std::cout << ans;
	return 0;
}