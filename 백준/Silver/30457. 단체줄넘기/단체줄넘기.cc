#include<iostream>
#include<vector>

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void sol(std::vector<int>& studs) {
	for (int i = 0; i < studs.size(); i++) {
		int small = i;
		for (int j = i + 1; j < studs.size(); j++) {
			if (studs[small] > studs[j]) {
				small = j;
			}
		}
		swap(studs[i], studs[small]);
	}

	int join_cnt = studs.size();
	int dupli_cnt = 0;
	for (int i = 0; i < studs.size()-1; i++) {
		if (studs[i] == studs[i + 1]) {
			if (dupli_cnt == 1) {
				join_cnt--;
			}
			else
				dupli_cnt ++;
		}
		else {
			dupli_cnt = 0;		
		}
	}
	std::cout << join_cnt;
}

int main(void) {
	int size;
	std::cin >> size;
	std::vector<int>stud_vec(size);
	for (int& elem : stud_vec) {
		std::cin >> elem;
	}
	sol(stud_vec);
	return 0;
}