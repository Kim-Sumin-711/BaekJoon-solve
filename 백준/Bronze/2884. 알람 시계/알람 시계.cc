#include<iostream>
using namespace std;
int main() {
	int H, M;
	cin >> H >> M;
	if (M >= 45)
		cout << H << " " << M - 45;
	else {
		if (H > 0)    cout << H - 1 << " " << 15 + M;
		else    cout << 23 << " " << 15 + M;
	}
	return 0;
}