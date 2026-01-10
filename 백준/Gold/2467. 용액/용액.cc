#include<iostream>
#include<vector>
#include<cmath>
//two pointer?

void set_solution_vec(std::vector<long long>& solution_vec) {
	for (long long& elem : solution_vec) {
		std::cin >> elem;
	}
}

void sol(const std::vector<long long>& solution_vec) {
	int p1=0, p2=solution_vec.size()-1;
	int ans1=0, ans2=0;
	long long the_solution_closest_to_zero = 2000000001;
	long long mixed_solution;
	while (p1 != p2) {
		mixed_solution = solution_vec[p1] + solution_vec[p2];
		if (std::abs(the_solution_closest_to_zero) > std::abs(mixed_solution)) {
			the_solution_closest_to_zero = mixed_solution;
			ans1 = p1; ans2 = p2;
		}
		if (mixed_solution == 0) break;
		else {
			if (mixed_solution < 0) p1++;
			else p2--;
		}
	}
	std::cout << solution_vec[ans1] << ' ' << solution_vec[ans2];
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int solution_cnt;
	std::cin >> solution_cnt;
	std::vector<long long> solution_vec(solution_cnt);
	set_solution_vec(solution_vec);
	sol(solution_vec);
	return 0;
}