#include<iostream>
#include<vector>
int main(void) {
	int N; std::cin >> N;
	std::vector<bool> vec(1001,false);
	for (int i = 1; i < 100; i++) {
		vec[i] = true;
	}
	for (int i = 1; i < 10; i++) {
		for (int d = -4; d < 5; d++) {
			short temp_1 = i+d, temp_2 = i+d+d;
			if (temp_1 >= 0 && temp_1 < 10 && temp_2>=0 && temp_2 < 10) {
				vec[i*100+temp_1 * 10 + temp_2] = true;
			}
			else continue;
		}
	}
	short ans = 0;
	for (int i = 1; i < N + 1; i++) {
		if (vec[i] == true) {
			ans++;
		}
	}
	std::cout << ans;
	return 0;
}