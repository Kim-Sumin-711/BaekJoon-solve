#include<iostream>
#include<vector>
#include<algorithm>

bool is_in(const int& target, const std::vector<int>& vec) {
	for (const int& elem : vec)
		if (elem == target)
			return true;
	return false;
}

void set_num_vec(std::vector<int>& num_vec,const int& total_cnt) {
	int tmp;
	for (int i = 0; i < total_cnt; i++) {
		std::cin >> tmp;
		if (!is_in(tmp, num_vec))
			num_vec.push_back(tmp);
	}
}

void print_vec(const std::vector<int>& vec) {
	for (const int& elem : vec) 
		std::cout << elem << " ";
	std::cout << "\n";
}

std::vector<int> extend_vec(std::vector<int> vec, const int target) {
	vec.push_back(target);
	return vec;
}

void print_num_array(const std::vector<int>& num_vec, std::vector<int> now, const int& need_cnt) {
	if (now.size() < need_cnt) {
		for (const int& elem : num_vec) {
			if (now.size() == 0)
				print_num_array(num_vec, extend_vec(now, elem), need_cnt);
			else
				if (elem >= *(now.end() - 1))
					print_num_array(num_vec, extend_vec(now, elem), need_cnt);
		}
	}
	else {
		print_vec(now);
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int total_cnt, need_cnt;
	std::cin >> total_cnt >> need_cnt;
	std::vector<int> num_vec;
	set_num_vec(num_vec, total_cnt);
	std::sort(num_vec.begin(),num_vec.end());
	print_num_array(num_vec, {}, need_cnt);
	return 0;
}