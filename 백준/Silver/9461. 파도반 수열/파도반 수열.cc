#include<iostream>
#include<vector>

void setPn(std::vector<long long>& vec) {
	vec[0] = 0;
	vec[1] = vec[2] = vec[3] = 1;
	vec[4] = vec[5] = 2;
	for (int i = 6; i < 101; i++)
		vec[i] = vec[i - 1] + vec[i - 5];
}

int main(void) {
	std::vector<long long> Pn(101);
	setPn(Pn);
	int test_case;
	std::cin >> test_case;
	while (test_case--) {
		int n;
		std::cin >> n;
		std::cout << Pn[n] << "\n";
	}
	return 0;
}
