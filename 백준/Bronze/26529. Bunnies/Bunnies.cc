#include<iostream>
int main(void) {
	int tc; std::cin >> tc;
	while (tc--) {
		int n; std::cin >> n;
		int fibo1=1, fibo2=1, temp;
		for (int i = 2; i < n+1; i++) {
			temp = fibo2;
			fibo2 += fibo1;
			fibo1 = temp;
		}
		std::cout << fibo2 << "\n";
	}
	return 0;
}