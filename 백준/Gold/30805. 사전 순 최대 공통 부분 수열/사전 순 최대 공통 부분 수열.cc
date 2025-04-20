#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>

void set_vec_and_map(std::vector<int>& vec, std::unordered_map<int, int>& map) {
	int size;
	std::cin >> size;
	for (int i = 0; i < size; i++) {
		int temp; std::cin >> temp;
		vec.push_back(temp);
		if (map.find(temp) != map.end()) map[temp] += 1;
		else map.insert(std::make_pair(temp, 1));
	}
}

void initialize(std::vector<int>& avec, std::vector<int>& bvec, std::vector<int>& common_vec) {
	std::unordered_map<int, int> amap, bmap;
	set_vec_and_map(avec, amap);
	set_vec_and_map(bvec, bmap);
	//save common elements by using unordered_map
	for (auto iter = amap.begin(); iter != amap.end(); iter++) {
		if (bmap.find(iter->first) != bmap.end()) {
			int cnt = std::min(iter->second, bmap[iter->first]);
			while (cnt--) {
				common_vec.push_back(iter->first);
			}
		}
	}
}

void find_answer(std::vector<int>& avec, std::vector<int>& bvec, std::vector<int>& common_vec) {
	std::vector<int> ans_vec;
	std::sort(common_vec.begin(), common_vec.end(), std::greater<int>());
	int a_cursor = 0, b_cursor = 0;
	for (int common : common_vec) {
		bool findA=false, findB=false;
		int tempA, tempB;
		for (int i = a_cursor; i < avec.size(); i++) {
			if (common == avec[i]) {
				tempA= i+1;
				findA = true;
				break;
			}
		}
		for (int j = b_cursor; j < bvec.size(); j++) {
			if (common == bvec[j]) {
				tempB = j+1;
				findB = true;
				break;
			}
		}
		if (findA && findB) {
			ans_vec.push_back(common);
			a_cursor = tempA;
			b_cursor = tempB;
		}
	}

	//print_ans
	std::cout << ans_vec.size() << "\n";
	for (auto iter = ans_vec.begin(); iter != ans_vec.end(); iter++) {
		std::cout << *iter << " ";
	}

}

int main(void)
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::vector<int> avec, bvec, common_vec;
	initialize(avec, bvec, common_vec);
	if (common_vec.empty()) std::cout << 0;
	else find_answer(avec, bvec, common_vec);
	return 0;
}