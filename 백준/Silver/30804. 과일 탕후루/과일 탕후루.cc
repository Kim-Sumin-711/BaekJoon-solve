#include<iostream>
#include<vector>

int get_dif_fruit_cnt(const std::vector<int>& fruits) {
	int res = 0;
	for (const int& elem : fruits) {
		if (elem != 0) {
			if (++res > 2)
				return 3;
		}	
	}
		
	return res;
}

int f(const std::vector<short>& tang, std::vector<int>& fruits, std::vector<int>& res, const int& len) {
	for (int i = res[1]+1; i < len; i++) {
		fruits[tang[i]]++;
		if (fruits[tang[i]] == 1) {
			if (get_dif_fruit_cnt(fruits) > 2) {
				fruits[tang[i]]--;
				res[1] = i - 1;
				res[2] = std::max(res[2], i - res[0]);
				return 0;
			}
		}
	}
	res[1] = len - 1;
	res[2] = std::max(res[2],len - res[0]);
	return 0;

}

int main(void) {
	int len,max_val=0;
	std::cin >> len;
	std::vector<short> tang(len);
	std::vector<int>fruits(10), res(3);
	for (int i = 0; i < len; i++) {
		std::cin >> tang[i];
	}
	fruits[tang[0]]++;
	for (int start = 0; start < len; start++) {
		res[0] = start;
		f(tang, fruits, res, len);
		if (res[1] == len - 1)
			break;
		else
			fruits[tang[start]]--;
	}
	std::cout << res[2];
	return 0;
}