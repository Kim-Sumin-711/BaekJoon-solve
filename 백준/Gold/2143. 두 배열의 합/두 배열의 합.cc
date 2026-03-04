#include<iostream>
#include<vector>
#include<unordered_map>

void create_sums_map(std::unordered_map<int, int>& map, const std::vector<int>& vec) {
	for (int elem : vec) {
		if (map.find(elem) != map.end()) map[elem]++;
		else map[elem] = 1;
	}
	for (int i = 0; i < vec.size(); i++) {
		int temp_sum = vec[i];
		for (int j = i + 1; j < vec.size(); j++) {
			temp_sum += vec[j];
			if (map.find(temp_sum) != map.end()) map[temp_sum]++;
			else map[temp_sum] = 1;
		}
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int T; std::cin >> T;
	int vec1_size, vec2_size;
	std::cin >> vec1_size;
	std::vector<int> vec1(vec1_size);
	for (int i = 0; i < vec1_size; i++) {
		std::cin >> vec1[i];
	}
	std::cin >> vec2_size;
	std::vector<int> vec2(vec2_size);
	for (int i = 0; i < vec2_size; i++) {
		std::cin >> vec2[i];
	}
	long long ans = 0;
	std::unordered_map<int, int> vec1_sums_map;
	create_sums_map(vec1_sums_map, vec1);
	
	for (int elem : vec2) {
		if (vec1_sums_map.find(T - elem) != vec1_sums_map.end()) {
			ans += vec1_sums_map[T - elem];
		}
	}
	for (int i = 0; i < vec2.size(); i++) {
		int temp_sum = vec2[i];
		for (int j = i + 1; j < vec2.size(); j++) {
			temp_sum += vec2[j];
			if (vec1_sums_map.find(T - temp_sum) != vec1_sums_map.end()) ans += vec1_sums_map[T - temp_sum];
		}
	}
	std::cout << ans;
	return 0;
}