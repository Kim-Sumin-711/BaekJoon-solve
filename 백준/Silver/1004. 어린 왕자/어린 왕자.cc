#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int get_enter_exit_cnt(vector<int>p1, vector<int>p2, vector<int>circle_info) {
	double dis1 = pow(pow(circle_info[0] - p1[0], 2) + pow(circle_info[1] - p1[1], 2), 0.5);
	double dis2 = pow(pow(circle_info[0] - p2[0], 2) + pow(circle_info[1] - p2[1], 2), 0.5);
	if (dis2 < circle_info[2] && dis1 < circle_info[2])
		return 0;
	else if (dis1 < circle_info[2] || dis2 < circle_info[2])
		return 1;
	else
		return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test;
	cin >> test;
	while (test--) {
		int startX, startY, goalX, goalY;
		cin >> startX >> startY >> goalX >> goalY;
		int system;
		cin >> system;
		int enter_exit_cnt = 0;
		while (system--) {
			int centerX, centerY, radius;
			cin >> centerX >> centerY >> radius;
			enter_exit_cnt += get_enter_exit_cnt({ startX,startY }, { goalX,goalY }, { centerX,centerY,radius });
		}
		cout << enter_exit_cnt << "\n";
	}
	return 0;
}