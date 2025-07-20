#include<iostream>
#include<vector>
#include<string>
int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::string ISBN;
	int val = 0;
	bool weight_factor = false, missing_space_weight_factor = false;
	std::cin >> ISBN;
	for (int i = 0; i < ISBN.size(); i++) {
		if (ISBN[i] == '*') {
			missing_space_weight_factor = weight_factor;
			weight_factor = !weight_factor;
			continue;
		}
		if (weight_factor) val += ((ISBN[i] - 48) * 3) % 10;
		else val += ISBN[i] - 48;
		val %= 10;
		weight_factor = !weight_factor;
	}
	if (val == 0) {
		std::cout << 0;
	}
	else {
		if (missing_space_weight_factor) {
			int temp = 10 - val;
			if (temp % 3 == 0) std::cout << temp / 3;
			else if ((temp + 10) % 3 == 0) std::cout << (temp + 10) / 3;
			else std::cout << (temp + 20) / 3;
		}
		else
			std::cout << 10 - val;
	}


	return 0;
}