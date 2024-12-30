#include<iostream>
using namespace std;
void print_matrix_one_to_star(int**, int);
void free_matrix(int**, int);

void print_matrix_one_to_star(int** m, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (m[row][col] == 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
}

void free_matrix(int** m, int size) {
	for (int i = 0; i < size; i++) {
		delete[] m[i];
	}
	delete[] m;
}

void get_ans_position_matrix(int** m, int size, int target_size) {
	if (target_size >= 3) {
		for (int row_cursor = target_size / 3; row_cursor < size; row_cursor = row_cursor + target_size) {
			for (int col_cursor = target_size / 3; col_cursor < size; col_cursor = col_cursor + target_size) {

				for (int row = row_cursor; row < row_cursor + target_size / 3; row++)
					for (int col = col_cursor; col < col_cursor + target_size / 3; col++)
						m[row][col] = 0;
			}
		}
		get_ans_position_matrix(m, size, target_size / 3);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int size;
	int** matrix;
	cin >> size;

	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			matrix[row][col] = 1;
		}
	}

	get_ans_position_matrix(matrix, size, size);
	print_matrix_one_to_star(matrix, size);
	free_matrix(matrix, size);
	
	return 0;
}