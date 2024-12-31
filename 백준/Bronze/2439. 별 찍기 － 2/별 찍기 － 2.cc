#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int _ = 0; _ < N - i ; _++)
			cout << " ";
		for (int _ = 0; _ < i; _++)
			cout << "*";
		cout << "\n";
	}
	return 0;
}