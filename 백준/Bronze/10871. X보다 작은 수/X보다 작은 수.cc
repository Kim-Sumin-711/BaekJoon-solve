#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N, X;
	cin >> N >> X;
	vector<int>num_vector(N);
	vector<int>res_vector;
	for (int& number : num_vector)
		cin >> number;
	for (int number : num_vector)
		if (X > number)
			res_vector.push_back(number);
	for (int res : res_vector)
		cout << res << " ";
	return 0;
}