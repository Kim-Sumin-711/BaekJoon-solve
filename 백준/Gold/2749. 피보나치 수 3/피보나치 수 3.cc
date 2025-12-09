#include<iostream>
#include<unordered_map>
#include<queue>
long long INF = 1000000;

void get_needed_N(long long N, std::unordered_map<long long, long long>& needed_N_map) {
	std::queue<long long> Ns;
	Ns.push(N);
	needed_N_map.insert({ N,-1 });
	while (!Ns.empty()) {
		long long now = Ns.front();
		Ns.pop();
		if (now < 4) continue;
		long long simplized_N = now / 2;
		if (needed_N_map.find(simplized_N) == needed_N_map.end()) {
			needed_N_map.insert({ simplized_N,-1 });
			Ns.push(simplized_N);
		}
		if (now % 2) {
			if (needed_N_map.find(simplized_N + 1) == needed_N_map.end()) {
				needed_N_map.insert({ simplized_N + 1,-1 });
				Ns.push(simplized_N + 1);
			}
		}
		else {
			if (needed_N_map.find(simplized_N - 1) == needed_N_map.end()) {
				needed_N_map.insert({ simplized_N - 1,-1 });
				Ns.push(simplized_N - 1);
			}
		}
	}
}

//recursion...
long long get_Fibonacci_number(long long N, std::unordered_map<long long, long long>& needed_N_map) {
	if (N == 0) return 0;
	if (N == 1) return 1;
	if (N == 2) return 1;
	if (N == 3) return 2;
	if (needed_N_map[N] != -1) {
		return needed_N_map[N];
	}
	long long simplized_N = N / 2;
	long long temp = get_Fibonacci_number(simplized_N, needed_N_map);
	needed_N_map[simplized_N] = temp;

	bool is_odd = N % 2;

	//F(N) == F(2n+1) == (F(n+1))^2 + (F(n))^2
	//N>3 and odd integer
	if (is_odd) {
		long long temp2 = get_Fibonacci_number(simplized_N + 1,needed_N_map);
		needed_N_map[simplized_N + 1] = temp2;
		long long fibo = ((temp * temp) % INF + (temp2 * temp2) % INF) % INF;
		needed_N_map[N] = fibo;
		return fibo;
	}
	//F(N) == F(2n) == ( F(n+1) + F(n-1) ) * F(n) --> (F(N))^2 + 2 * F(N-1) * F(N) 
	//N>=2 and even integer
	else {
		long long temp2 = get_Fibonacci_number(simplized_N - 1, needed_N_map);
		needed_N_map[simplized_N - 1] = temp2;
		long long fibo = ((temp * temp) % INF + (2 * temp * temp2) % INF) % INF;
		needed_N_map[N] = fibo;
		return fibo;
	}
}

int main(void) {
	long long N;
	std::cin >> N;
	
	std::unordered_map<long long, long long> needed_N_map;
	get_needed_N(N, needed_N_map);
	long long Fibonacci_number_of_N = get_Fibonacci_number(N,needed_N_map);
	std::cout << Fibonacci_number_of_N;
	return 0;
}