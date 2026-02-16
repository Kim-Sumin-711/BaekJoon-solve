#include<iostream>
#include<algorithm>
#include<vector>
void set_vec(std::vector<short>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cin >> vec[i];
	}
}

int main(void) {
	int N; std::cin >> N;
	std::vector<short> A(N,0), B(N,0);
	set_vec(A); set_vec(B);
	std::sort(A.begin(), A.end(), std::greater<short>()); std::sort(B.begin(), B.end());
	int ans = 0;
	for (int i = 0; i < N; i++) ans += A[i] * B[i];
	std::cout << ans;
	return 0;
}