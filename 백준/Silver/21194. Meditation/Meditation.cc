#include<iostream>
#include<vector>
#include<algorithm>

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> vec(n);
	for (int& elem : vec) {
		std::cin >> elem;
	}
	int sum=0;
	std::sort(vec.begin(), vec.end(),compare);
	for (int i = 0; i < k; i ++) {
		sum += vec[i];
	}
	std::cout << sum;
	return 0;
}