#include<iostream>
#include<string>
#include<cmath>
#include<vector>
std::pair<int,int> get_matrix_size(int text_size) {
	int R = 0, C = 0;
	int loop = std::sqrt(text_size);
	for (int i = 1; i <= loop; i++) {
		if (text_size % i == 0) {
			R = i; C = text_size / i;
		}
	}
	return { R,C };
}

void decode(const std::pair<int, int>& matrix_size, const std::string& text) {
	std::vector<std::vector<char>> text_matrix(matrix_size.first, std::vector<char>(matrix_size.second, 0));
	for (int c = 0; c < matrix_size.second; c++) {
		for (int r = 0; r < matrix_size.first; r++) {
			text_matrix[r][c] = text[matrix_size.first*c+r];
		}
	}
	//print
	for (int r = 0; r < matrix_size.first; r++) {
		for (int c = 0; c < matrix_size.second; c++) {
			std::cout << text_matrix[r][c];
		} 
	}

}

int main(void) {
	std::string text;
	std::cin >> text;
	int text_size = text.size();
	std::pair<int, int> matrix_size = get_matrix_size(text_size);
	decode(matrix_size, text);
	return 0;
}