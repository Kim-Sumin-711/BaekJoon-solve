#include<iostream>
#include<vector>

void print_vec(const std::vector<short>& vec) {
	for (const short& elem : vec) {
		std::cout << elem << ' ';
	}
	std::cout << "\n";
}

void print_buble_sort_log(std::vector<short>& vec) {
	int loop = 4;
	while (loop--) {
		for (int i = 0; i < 4; i++) {
			if (vec[i] > vec[i + 1]) {
				short temp = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = temp;
				print_vec(vec);
			}
		}
	}
}

int main(void) {
	std::vector<short> vec(5);
	for (short& elem : vec) {
		std::cin >> elem;
	}
	print_buble_sort_log(vec);
	return 0;
}