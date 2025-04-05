#include<iostream>
#include<vector>
#include<stack>
int get_position(const std::vector<int>& dp, int target) {
	int left = 0, right = dp.size() - 1;
	do {
		int mid = (left + right) / 2;
		if (dp[mid] > target) {
			right = mid-1;
		}
		else if (dp[mid] < target) {
			left = mid+1;
		}
		else {
			return mid;
		}
	} while (left < right);
	if (dp[left] > target) return left;
	else if (dp[left] < target) return left + 1;
	else return left;

}

void Print_LIS_and_len(int len, const std::vector<int>& vec) {
	std::vector<int>dp(1,vec[0]);
	std::vector<int>log(len,-1);
	log[0] = 0;
	int dp_size = 0;
	for (int i = 1; i < len; i++) {
		if (vec[i] > dp[dp_size]) {
			dp.push_back(vec[i]);
			dp_size++;
			log[i] = dp_size;
		}
		else if(vec[i] < dp[dp.size()-1]){
			int position = get_position(dp, vec[i]);
			dp[position] = vec[i];
			log[i] = position;
		}
	}
	std::cout << dp_size + 1 << "\n";
	std::stack<int> LIS;
	int find = dp_size, idx = len-1;
	while (find != -1) {
		for (int i = idx; i >= 0; i--) {
			if (log[i] == find) {
				idx = i;
				find--;
				LIS.push(vec[idx]);
				break;
			}
		}
	}
	while (!LIS.empty()) {
		std::cout << LIS.top() << " ";
		LIS.pop();
	}

}



int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int len;
	std::cin >> len;
	std::vector<int> num_series(len, 0);
	for (auto iter = num_series.begin(); iter != num_series.end(); iter++) {
		std::cin >> *iter;
	}
	Print_LIS_and_len(len, num_series);
	return 0;
}