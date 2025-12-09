#include<iostream>
long long INF = 1000000007;
//recursion...
long long get_Fibonacci_number(long long N) {

	if (N == 0) return 0;
	if (N == 1) return 1;
	if (N == 2) return 1;
	if (N == 3) return 2;

	bool is_odd = N % 2;

	//F(N) == F(2n+1) == (F(n+1))^2 + (F(n))^2
	//N>3 and odd integer
	if (is_odd) {
		long long simplized_N = (N - 1) / 2;
		long long temp = get_Fibonacci_number(simplized_N + 1);
		long long temp2 = get_Fibonacci_number(simplized_N);
		return ((temp * temp) % INF + (temp2 * temp2) % INF) % INF;
	}
	//F(N) == F(2n) == ( F(n+1) + F(n-1) ) * F(n) --> (F(N))^2 + 2 * F(N-1) * F(N) 
	//N>=2 and even integer
	else {
		long long simplized_N = N / 2;
		long long temp = get_Fibonacci_number(simplized_N-1);
		long long temp2 = get_Fibonacci_number(simplized_N);
		return ((temp2 * temp2) % INF + (2 * temp * temp2) % INF) % INF;
	}
}

int main(void) {
	int N;
	std::cin >> N;
	long long Fibonacci_number_of_N = get_Fibonacci_number(N);
	std::cout << Fibonacci_number_of_N;
	return 0;
}