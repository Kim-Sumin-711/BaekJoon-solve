#include<iostream>
#include<vector>
#include<algorithm>

void set_num_vec(std::vector<int>& num_vec) {
	for (int& elem : num_vec)
		std::cin >> elem;
}

void set_select_vec(std::vector<int>& select_vec, const int& need_cnt) {
	for (int i = 0; i < need_cnt; i++)
		select_vec[i] = 1;
}

void print_vec(const std::vector<std::vector<int>>& vec) {
	for (const std::vector<int>& elem_vec : vec) {
		for (const int& elem : elem_vec)
			std::cout << elem << " ";
		std::cout << "\n";
	}
}

std::vector<int> get_selected_vec_from_select_vec(const std::vector<int>& num_vec, const std::vector<int>& select_vec) {
	std::vector<int> res;
	for (int i = 0; i < select_vec.size(); i++) {
		if (select_vec[i] == 1)
			res.push_back(num_vec[i]);
	}
	return res;
}

bool is_equal_vec(const std::vector<int>& vec1, const std::vector<int>& vec2) {
	for (int i = 0; i < vec1.size(); i++) {
		if (vec1[i] != vec2[i])
			return false;
	}
	return true;
}


bool find_equal_vec(const std::vector<std::vector<int>>& vec, const std::vector<int>& target) {
	for (const std::vector<int>& elem : vec)
		if (is_equal_vec(elem, target))
			return true;
	return false;
}

void save_all_permutation_of_given_vec(std::vector<std::vector<int>>& save, std::vector<int>& given_vec) {
	std::sort(given_vec.begin(), given_vec.end());
	save.push_back(given_vec);
	while (std::next_permutation(given_vec.begin(), given_vec.end())) {
		save.push_back(given_vec);
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int total_num_cnt, need_cnt;
	std::cin >> total_num_cnt >> need_cnt;
	std::vector<int> num_vec(total_num_cnt);
	std::vector<int> select_vec(total_num_cnt);

	set_num_vec(num_vec);
	set_select_vec(select_vec,need_cnt);
	std::sort(num_vec.begin(), num_vec.end());

	std::vector<std::vector<int>> already_selected_vec;
	std::vector<std::vector<int>> res;

	do {
		std::vector<int> sliced_num_vec = get_selected_vec_from_select_vec(num_vec, select_vec);
		if (!find_equal_vec(already_selected_vec, sliced_num_vec)) {
			already_selected_vec.push_back(sliced_num_vec);
			save_all_permutation_of_given_vec(res,sliced_num_vec);
		}
		else
			continue;	
	} while (std::prev_permutation(select_vec.begin(), select_vec.end()));
	
	std::sort(res.begin(), res.end());
	print_vec(res);

	
	
	return 0;
}