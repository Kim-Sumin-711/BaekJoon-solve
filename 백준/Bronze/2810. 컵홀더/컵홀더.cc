#include<iostream>
int main(void) {
	int N; std::cin >> N;
	int ans = 0;
	bool there_is_L = false;
	while (N--) {
		char sit;
		std::cin >> sit;
		if (sit == 'S') {
			ans++;
		}
		else {
			N--; std::cin >> sit;
			if (there_is_L) ans++;
			else ans += 2;
			there_is_L = true;
		}
	}
	std::cout << ans;
	return 0;
}