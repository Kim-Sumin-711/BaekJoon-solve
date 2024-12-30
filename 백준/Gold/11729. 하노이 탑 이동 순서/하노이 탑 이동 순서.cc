#include<iostream>
#include<cmath>
using namespace std;
void hanoi_sol(int, char, char, char);

void hanoi_sol(int disk_cnt, char start, char by, char end) {
	if (disk_cnt == 1)
		cout << start << " " << end << "\n";
	else {
		hanoi_sol(disk_cnt-1, start, end, by);
		cout << start << " " << end << "\n";
		hanoi_sol(disk_cnt - 1, by, start, end);
	}
}

int main()
{
	int disk_cnt;
	cin >> disk_cnt;
	cout << (long long int)pow(2,disk_cnt) - 1 << "\n";
	hanoi_sol(disk_cnt, '1', '2', '3');
	return 0;
}