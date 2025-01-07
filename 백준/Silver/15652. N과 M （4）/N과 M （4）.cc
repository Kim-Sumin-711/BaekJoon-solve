#include<iostream>
#include<vector>

void print_each_vec(const std::vector<int>& vec) {
	for (const int& elem : vec)
		std::cout << elem << " ";
	std::cout << "\n";
}

void print_vecs_that_start_given_num(const std::vector<int>& num_array_vec, std::vector<int> tmp_res_vec, int start, int oper_cnt) {
	if (tmp_res_vec.size() == oper_cnt) {
		print_each_vec(tmp_res_vec);
	}
	else if (tmp_res_vec.size() > oper_cnt) {
		for (int next = start; next < num_array_vec.size(); next++) {
			tmp_res_vec[oper_cnt] = num_array_vec[next];
			print_vecs_that_start_given_num(num_array_vec, tmp_res_vec, next, oper_cnt + 1);
			
		}
			
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cout.tie(0);
	int N, M;
	std::cin >> N >> M;
	std::vector<int> one_to_N_vec(N), tmp_res_vec(M);
	for (int elem = 1; elem < N + 1; elem++) {
		one_to_N_vec[elem - 1] = elem;
	}
	for (int start = 0; start < one_to_N_vec.size(); start++) {
		tmp_res_vec[0] = one_to_N_vec[start];
		print_vecs_that_start_given_num(one_to_N_vec, tmp_res_vec, start, 1);
	}
	
		
	return 0;
}