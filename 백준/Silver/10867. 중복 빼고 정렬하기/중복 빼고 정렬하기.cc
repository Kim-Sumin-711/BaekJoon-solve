#include<iostream>
#include<vector>
int main(void) {
	int N; std::cin >> N;
	std::vector<bool> vec(2001);
	while (N--) {
		short temp; std::cin >> temp;
		vec[temp + 1000] = true;
	}
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == true) {
			std::cout << i - 1000 << ' ';
		}
	}

	return 0;
}