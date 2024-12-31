#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int>num_vector(N);
	for (int& number : num_vector)
		cin >> number;
	int max = -1000001, min = 1000001;
	for (int number : num_vector) {
		if (max < number)
			max = number;
		if (min > number)
			min = number;
	}
	cout << min << " " << max;
	return 0;
}