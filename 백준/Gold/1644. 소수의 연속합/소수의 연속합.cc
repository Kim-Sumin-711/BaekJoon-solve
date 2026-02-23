#include<iostream>
#include<vector>
#include<cmath>
void set_sosu(std::vector<bool>& sosu_bool, std::vector<int>& sosu) {
	for (int i = 2; i <= (int)std::sqrt(sosu_bool.size()); i++) {
		if (sosu_bool[i] == false) continue;
		for (int j = i*i; j < sosu_bool.size(); j+=i) {
			sosu_bool[j] = false;
		}
	}
	for (int i = 2; i < sosu_bool.size(); i++) {
		if (sosu_bool[i] == true) sosu.push_back(i);
	}
}

int main(void) {
	int n; std::cin >> n;
	std::vector<bool> sosu_bool(n+1,true);
	std::vector<int> sosu;
	set_sosu(sosu_bool,sosu);
	int dp = 0; int ans = 0; int sp_idx = 0;
	for (int i : sosu) {
		dp += i;
		if (dp== n)	ans++;
		else {
			while (dp > n) {
				dp -= sosu[sp_idx];
				sp_idx++;
			}
			if (dp == n) ans++;
		}
	}
	std::cout << ans;
	return 0;
}