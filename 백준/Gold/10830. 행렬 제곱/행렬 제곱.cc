#include<iostream>
#include<vector>
using Matrix = std::vector<std::vector<int>>;

void set_matrix(Matrix& matrix) {
	for (std::vector<int>& row : matrix) {
		for (int& elem : row) {
			std::cin >> elem;
		}
	}
}

Matrix multiply_matrix(const Matrix& m1, const Matrix& m2) {
	int size = m1.size();
	Matrix result(size, std::vector<int>(size,0));
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			int sum = 0;
			for (int i = 0; i < size; i++)
				sum += m1[row][i] * m2[i][col];
			result[row][col] = sum;
		}
	}
	return result;
}

void print_matrix(const Matrix& matrix) {
	for (const std::vector<int>& row : matrix) {
		for (const int& elem : row)
			std::cout << elem << " ";
		std::cout << "\n";
	}
}

void make_each_elem_under_1000(Matrix& matrix) {
	for (std::vector<int>& row : matrix) {
		for (int& elem : row) {
			if (elem >= 1000)
				elem %= 1000;
		}
	}
}

Matrix get_result(long long calc_cnt, const Matrix& matrix) {
	if (calc_cnt == 1)
		return matrix;
	else {
		Matrix divided_matrix = get_result(calc_cnt / 2, matrix);
		if (calc_cnt % 2) {
			Matrix result = (multiply_matrix(divided_matrix, divided_matrix));
			make_each_elem_under_1000(result);
			result = multiply_matrix(result, matrix);
			make_each_elem_under_1000(result);
			return result;
		}
		else {
			Matrix result = multiply_matrix(divided_matrix, divided_matrix);
			make_each_elem_under_1000(result);
			return result;
		}
	}
}

void sol(const long long& calc_cnt, Matrix& matrix) {
	if (calc_cnt == 1) {
		make_each_elem_under_1000(matrix);
		print_matrix(matrix);
	}
	else {
		Matrix result = get_result(calc_cnt, matrix);
		print_matrix(result);
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int size;
	long long calc_cnt;
	std::cin >> size >> calc_cnt;
	Matrix matrix(size, std::vector<int>(size, 0));
	set_matrix(matrix);
	sol(calc_cnt, matrix);
	return 0;
}