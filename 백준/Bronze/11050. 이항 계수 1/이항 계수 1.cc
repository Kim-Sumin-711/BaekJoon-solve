#include<iostream>
int main(void) {
	int n, k;
	std::cin >> n >> k;
	long int boonmo = 1, boonja = 1;
	if (n / 2 < k) {
		k = n - k;
	}
	for (int i = 0; i < k; i++) {
		boonja *= (n - i);
	}
	for (int i = 2; i <= k; i++) {
		boonmo *= i;
	}
	std::cout << boonja / boonmo;

	return 0;
}
