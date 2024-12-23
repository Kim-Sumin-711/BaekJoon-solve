#include<iostream>
#include<vector>

std::vector<std::vector<int>> set_map(const int& size) {
	std::vector<std::vector<int>> vec(size,std::vector<int>(size));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cin >> vec[i][j];
		}
	}
	return vec;
}

int count_col_trees(const std::vector<std::vector<int>>&map, const int& col) {
	int res=0,now=0;
	for (int i = 0; i < map.size(); i++) {
		if (now < map[i][col]) {
			now = map[i][col];
			res += 1;
		}
	}
	return res;
}

int count_row_trees(const std::vector<std::vector<int>>& map, const int& row) {
	int res = 0, now = 0;
	for (int i = 0; i < map.size(); i++) {
		if (now < map[row][i]) {
			now = map[row][i];
			res += 1;
		}
	}
	return res;
}

void sol(const int& size) {
	std::vector<std::vector<int>>map = set_map(size);
	for (int col = 0; col < map.size(); col++) {
		std::cout << count_col_trees(map, col) << " ";
	}
	std::cout << "\n";
	for (int row = 0; row < map.size(); row++) {
		std::cout << count_row_trees(map, row) << "\n";
	}
}	

int main(void) {
	int size;
	std::cin >> size;
	sol(size);
	return 0;
}