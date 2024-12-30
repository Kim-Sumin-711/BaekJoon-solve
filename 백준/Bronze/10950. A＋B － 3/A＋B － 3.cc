#include<iostream>
using namespace std;
int main() {
	int test_case, A, B;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		cin >> A >> B;
		cout << A + B << endl;
	}
	return 0;
}