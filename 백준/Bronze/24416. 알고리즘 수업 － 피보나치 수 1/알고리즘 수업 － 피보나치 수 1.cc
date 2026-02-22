#include<iostream>
int main(void) {
	int n; std::cin >> n;
	int fibo1=1, fibo2=1, temp=0;
	for (int i = 3; i < n + 1; i++) {
		temp = fibo2;
		fibo2 += fibo1;
		fibo1 = temp;
	}
	std::cout << fibo2 << ' ' << n - 2;
	return 0;
}