#include<iostream>
#include<vector>
#include<algorithm>
void print_each_vec(const std::vector<int>& vec) {
	for (const int& elem : vec)
		std::cout << elem << " ";
	std::cout << "\n";
}

void print_vecs_that_start_given_num(const std::vector<int>& num_array_vec, std::vector<int> tmp_res_vec, std::vector<bool> visit,int start, int oper_cnt) {
	if (tmp_res_vec.size() == oper_cnt) {
		print_each_vec(tmp_res_vec);
	}
	else if (tmp_res_vec.size() > oper_cnt) {
		for (int next = 0; next < num_array_vec.size(); next++) {
			if (!visit[next]) {
				tmp_res_vec[oper_cnt] = num_array_vec[next];
				visit[next] = true;
				print_vecs_that_start_given_num(num_array_vec, tmp_res_vec, visit, next, oper_cnt + 1);
				visit[next] = false;
			}
		}

	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cout.tie(0);
	int N, M;
	std::cin >> N >> M;
	std::vector<int> one_to_N_vec(N), tmp_res_vec(M);
	std::vector<bool>visit(N);
	for (int elem = 0; elem < N; elem++) {
		std::cin >> one_to_N_vec[elem];
	}
	std::sort(one_to_N_vec.begin(), one_to_N_vec.end());
	for (int start = 0; start < one_to_N_vec.size(); start++) {
		tmp_res_vec[0] = one_to_N_vec[start];
		visit[start] = true;
		print_vecs_that_start_given_num(one_to_N_vec, tmp_res_vec, visit, start, 1);
		visit[start] = false;
	}


	return 0;
}