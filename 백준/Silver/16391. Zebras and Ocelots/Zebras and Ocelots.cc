#include<iostream>
#include<vector>
int main(void) {
	int N; std::cin >> N;
	std::vector<char> zoo_pile(N);
	for (char& ch : zoo_pile) {
		std::cin >> ch;
	}
	std::vector<long long> two_floors(60);
	long long two_floor = 1;
	for (int i = 0; i < 60; i++) {
		two_floors[i] = two_floor;
		two_floor *= 2;
	}
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		if (zoo_pile[i] == 'O') {
			ans += two_floors[N - i -1];
		}
	}
	std::cout << ans;

	return 0;
}