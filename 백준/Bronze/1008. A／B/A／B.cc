#include<iostream>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	cout.precision(9);
	cout << fixed;
	cout << A / double(B);
	return 0;
}