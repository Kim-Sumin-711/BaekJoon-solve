#include<iostream>
#include<vector>
using Matrix = std::vector<std::vector<int>>;

void set_matrix(Matrix& matrix) {
	for (std::vector<int>& each_row : matrix) {
		for (int& elem : each_row) {
			std::cin >> elem;
		}
	}
}

void set_two_find(std::vector<long long>& two_find) {
	int loop = 38;
	long long twos = 1;
	while (loop--) {
		two_find.push_back(twos);
		twos *= 2;
	}
}

void make_matrix_elems_small(Matrix& m) {
	for (std::vector<int>& row : m) {
		for (int& elem : row) {
			if (elem >= 1000) elem %= 1000;
		}
	}
}

Matrix matrix_multiply(const Matrix& m1, const Matrix& m2) {
	Matrix result(m1.size(), std::vector<int>(m1.size(), 0));
	for (int row = 0; row < m1.size(); row++) {
		for (int col = 0; col < m1.size(); col++) {
			int sum = 0;
			for (int i = 0; i < m1.size(); i++) {
				sum += (m1[row][i] * m2[i][col]);
			}
			result[row][col] = sum;
		}
	}
	make_matrix_elems_small(result);
	return result;
}

short set_two_check_and_get_true_cnt(std::vector<bool>& two_check, const std::vector<long long>& two_find, long long cal_cnt) {
	short cnt = 0;
	while (cal_cnt > 1) {
		for (int i = 1; i < 38; i++) {
			if (cal_cnt < two_find[i]) {
				cal_cnt -= two_find[i-1];
				two_check[i-1] = true;
				cnt++;
				break;
			}
		}
	}
	if (cal_cnt == 1) {
		cnt++;
		two_check[0] = true;
	}
	return cnt;
}

void print_matrix(const Matrix& matrix) {
	for (const std::vector<int>& each_row : matrix) {
		for (const int& elem : each_row) {
			std::cout << elem << " ";
		}
		std::cout << "\n";
	}
}

void sol(const long long& cal_cnt, Matrix& original_matrix) {
	std::vector<long long> two_find;
	set_two_find(two_find);
	std::vector<bool> two_check(37,false);
	short cnt = set_two_check_and_get_true_cnt(two_check, two_find, cal_cnt);
	Matrix result_matrix(original_matrix.size(),std::vector<int>(original_matrix.size(),0));
	for (int i = 0; i < original_matrix.size(); i++) {
		result_matrix[i][i] = 1;
	}
	for (int i = 0; i < 37; i++) {
		if (cnt == 0) break;
		if (two_check[i]) {
			cnt--;
			result_matrix = matrix_multiply(result_matrix, original_matrix);
		}
		original_matrix = matrix_multiply(original_matrix, original_matrix);
	}
	print_matrix(result_matrix);
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	//initalization
	int size;
	long long cal_cnt;
	std::cin >> size >> cal_cnt;
	Matrix matrix(size, std::vector<int>(size, 0));
	set_matrix(matrix);
	sol(cal_cnt, matrix);
	return 0;
}
