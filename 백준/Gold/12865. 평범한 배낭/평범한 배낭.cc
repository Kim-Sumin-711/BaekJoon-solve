#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
void set_obj_vec(std::vector<std::pair<int, int>>& obj_vec) {
	for (std::pair<int, int>& each_obj : obj_vec)
		std::cin >> each_obj.first >> each_obj.second;
}


void set_val_dp(std::vector<int>& val_dp, const std::vector<std::pair<int, int>>& obj_vec,const int& max_weight) {
	for (const std::pair<int, int>& each_obj : obj_vec) {
		for (int w = max_weight; w > 0; w--) {
			if (w + each_obj.first <= max_weight)
				val_dp[w + each_obj.first] = std::max(val_dp[w + each_obj.first], each_obj.second + val_dp[w]);
		}
		if(each_obj.first <= max_weight)
			val_dp[each_obj.first] = std::max(val_dp[each_obj.first], each_obj.second);
	}
	
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int obj_cnt, max_weight;
	std::cin >> obj_cnt >> max_weight;
	std::vector<int> val_dp(max_weight + 1,0);
	std::vector<std::pair<int, int>> obj_vec(obj_cnt);
	set_obj_vec(obj_vec);
	set_val_dp(val_dp, obj_vec, max_weight);
	std::cout << *std::max_element(val_dp.begin(), val_dp.end());
	return 0;
}