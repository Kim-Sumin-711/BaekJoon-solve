#include<iostream>
#include<vector>
#include<cmath>
void set_vecs(std::vector<long long>& xvec, std::vector<long long>& yvec) {
	for (int i = 0; i < xvec.size();i++) {
		std::cin >> xvec[i] >> yvec[i];
	}
}
void sol(const std::vector<long long>& xvec, const std::vector<long long>& yvec, int size) {
	long long area = 0;
	for (int i = 0; i < size-1; i++) {
			area += xvec[i] * yvec[i + 1] - yvec[i] * xvec[i + 1];
	}
	area += xvec[size - 1] * yvec[0] - yvec[size - 1] * xvec[0];
	area = std::abs(area);
	if (area % 2 == 1) std::cout << area / 2 << ".5";
	else std::cout << area / 2 << ".0";
}
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int N;
	std::cin >> N;
	std::vector<long long> xvec(N, 0), yvec(N, 0);
	set_vecs(xvec, yvec);
	sol(xvec,yvec,N);
	return 0;
}