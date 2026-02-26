#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

void sol(const std::vector<int>& solution_vec) {
	int p1=0, p2=solution_vec.size()-1;
	int ans = 2100000000, ans_p1 = 0, ans_p2 = 0;
	while (p1 != p2) {
		int temp = solution_vec[p1] + solution_vec[p2];
		if (std::abs(ans) > std::abs(temp)) {
			ans = temp;
			ans_p1 = p1;
			ans_p2 = p2;
		}
		if (temp > 0) {
			p2--;
		}
		else if (temp < 0) {
			p1++;
		}
		else break;
	}
	std::cout << solution_vec[ans_p1] << ' ' << solution_vec[ans_p2];
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int N; std::cin >> N;
	std::vector<int> solutions_vec(N);
	bool there_is_acid = false, there_is_ph8plus = false;

	for (int i = 0; i < N; i++) {
		std::cin >> solutions_vec[i];
		if (solutions_vec[i] > 0) there_is_acid = true;
		else if (solutions_vec[i] < 0) there_is_ph8plus = true;
	}
	std::sort(solutions_vec.begin(), solutions_vec.end());
	if (there_is_ph8plus == false) {
		std::cout << solutions_vec[0] << ' ' << solutions_vec[1];
	}
	else if (there_is_acid == false) {
		std::cout << solutions_vec[solutions_vec.size() - 2] <<  ' ' << solutions_vec[solutions_vec.size() - 1];
	}
	else
		sol(solutions_vec);
	return 0;
}