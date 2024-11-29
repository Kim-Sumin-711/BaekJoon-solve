#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<vector<long long int>> dp(1);
	dp[0] = { 1,0 };
	int test_case, dp_calced=0;
	cin >> test_case;

	while (test_case--) {
		int num;
		cin >> num;
		while (dp_calced < num) {
			dp.push_back({ dp[dp_calced][1], dp[dp_calced][0] + dp[dp_calced][1] });
			dp_calced++;
		}
		cout << dp[num][0] << " " << dp[num][1] << endl;
	}
	return 0;
}