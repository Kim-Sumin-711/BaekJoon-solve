#include<iostream>
#include<vector>
#include<algorithm>
int main(void) {
	int L; std::cin >> L;
	std::vector<short> S(L);
	for (int i = 0; i < L; i++) {
		std::cin >> S[i];
	}
	short n; std::cin >> n;
	short left_border = 0, right_border = 0;
	std::sort(S.begin(), S.end());
	for (int i = 0; i < L; i++) {
		if (n == S[i]) {
			std::cout << 0;
			return 0;
		}
		else if (n < S[i]) {
			if (i == 0) left_border = 1;
			else left_border = S[i - 1];
			right_border = S[i];
			break;
		}
	}
	//1
	if (n==1) {
		std::cout << right_border - 2;
	}
	else {
		int ans=0;
		if(left_border!=1)
			ans = (n - left_border - 1) * (right_border - n) + right_border - n - 1;
		else if (S[0] == 1) {
			ans = (n - left_border - 1) * (right_border - n) + right_border - n - 1;
		}
		else {
			ans = (n-1) * (right_border - n) + right_border - n - 1;
		}
		std::cout << ans;
	}
	return 0;
}