#include<iostream>
#include<vector>

void set_vec(std::vector<int>& vec) {
	for (int& elem : vec)
		std::cin >> elem;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void reverse_vec(std::vector<int>& vec, int start, int end) {
	for (int i = start; i <= (end + start) / 2; i++)
		swap(vec[i], vec[end - i + start]);
}

int find_elem(const std::vector<int>& vec, const int& target) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == target)
			return i;
	}
}

void print_vec(const std::vector<int>& vec) {
	for (const int& elem : vec)
		std::cout << elem << " ";
}

void sol(std::vector<int>& vec) {
	int op_cnt = 0;
	std::vector<std::vector<int>> op_res;
	for (int i = 1; i < vec.size(); i++) {
		int index = find_elem(vec, i);
		if (index == i - 1)
			continue;
		else {
			op_cnt++;
			if (i-1 < index) {
				op_res.push_back({ i, index+1 });
				reverse_vec(vec, i - 1, index);
			}
			else {
				op_res.push_back({index + 1 ,i });
				reverse_vec(vec, index,i-1);
			}
		}
	}
	if (op_cnt == 0)
		std::cout << 0;
	else {
		std::cout << op_cnt << "\n";
		for (const std::vector<int>& elem_vec : op_res) {
			print_vec(elem_vec);
			std::cout << "\n";
		}
	}
}

int main(void) {
	int N;
	std::cin >> N;
	std::vector<int> vec(N);
	set_vec(vec);
	sol(vec);
	return 0;
}