#include<iostream>
#include<vector>
int main(void) {
	int N; std::cin >> N;
	std::vector<int>stu(N);
	for (int i = 0; i < N; i++) {
		stu[i] = i+1;
	}
	for (int i = 0; i < N; i++) {
		int num; std::cin >> num;
		for (int j = i; j > i - num; j--) {
			int temp = stu[j];
			stu[j] = stu[j - 1];
			stu[j - 1] = temp;
		}
	}
	for (int i : stu) {
		std::cout << i << ' ';
	}

	return 0;
}