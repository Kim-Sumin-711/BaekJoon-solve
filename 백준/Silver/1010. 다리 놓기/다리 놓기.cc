#include<iostream>
#include<vector>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int T; std::cin >> T;
	while (T--) {
		int N, M; std::cin >> N >> M;
		long long ans = 1;
		if (M == N) {
			std::cout << 1 << "\n";
			continue;
		}
		std::vector<int> up_part(N), down_part(N);
		for (int i = 0 ; i < up_part.size();i++){
			up_part[i] = M - i;
		}
		for (int i = 0; i < down_part.size(); i++) {
			down_part[i] = i+1;
		}
		bool up_done = false, down_done = false;
		int up_index = 0, down_index = 0;
		while (true) {
			if (up_done == true && down_done == true) break;
			else {
				if (up_done == true) {
					if (ans % down_part[down_index] == 0) {
						ans /= down_part[down_index];
						down_index++;
						if (down_index == N) down_done = true;
					}
					else std::cout << "sth goes wrong ㅜ.ㅜ\n";
				}
				else if (down_done == true) {
					ans *= up_part[up_index];
					up_index++;
					if (up_index == N)up_done = true;
				}
				else {
					ans *= up_part[up_index];
					up_index++;
					if(ans % down_part[down_index] == 0) {
						ans /= down_part[down_index];
						down_index++;
					}
					if (up_index == N) up_done = true;
					if (down_index == N) down_done = true;
				}
			}
		}
		std::cout << ans << "\n";

	}
}