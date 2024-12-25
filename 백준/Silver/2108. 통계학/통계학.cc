#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>

int sansul_avg(const std::vector<short int>& vec) {
	int sum = 0;
	for (const int& elem : vec) {
		sum += elem;
	}
	return round(sum / (double)vec.size());
}
short int middle_num(const std::vector<short int>& vec) {
	return vec[(vec.size() - 1) / 2];
}

short int most_freq_num(const std::vector<short int>& vec) {
	int max = 1;
	int count = 0;
	int now = vec[0];
	std::vector<int> freq_vec;
	for (const short int& elem : vec) {
		if (now == elem) {
			count += 1;
		}
		else {
			if (max < count) {
				max = count;
				freq_vec.clear();
				freq_vec.push_back(now);
			}
			else if (max == count) {
				freq_vec.push_back(now);
			}
			now = elem;
			count = 1;
		}
	}
	if (count == max) {
		freq_vec.push_back(now);
	}
	else if (count > max) {
		return now;
	}

	if (freq_vec.size() == 1) {
		return freq_vec[0];
	}
	else if (freq_vec.size() == 2) {
		return std::max(freq_vec[0], freq_vec[1]);
	}
	else if (freq_vec.size() == 0) {
		return now;
	}
	else {
		std::sort(freq_vec.begin(), freq_vec.end());
		return freq_vec[1];
	}
}

short int max_minus_min(const std::vector<short int>& vec) {
	return vec[vec.size() - 1] - vec[0];
}

int main(void) {
	int n,tmp;
	std::cin >> n;
	std::vector<short int>num_vector;
	while (n--) {
		std::cin >> tmp;
		num_vector.push_back(tmp);
	}
	std::sort(num_vector.begin(), num_vector.end());
	std::cout << sansul_avg(num_vector) << "\n";
	std::cout << middle_num(num_vector) << "\n";
	std::cout << most_freq_num(num_vector) << "\n";
	std::cout << max_minus_min(num_vector) << "\n";

	return 0;
}