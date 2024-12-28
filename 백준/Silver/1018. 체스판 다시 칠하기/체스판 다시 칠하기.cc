#include<iostream>
#include<vector>
using namespace std;

void set_board(std::vector<std::string>& vec) {
	for (std::string& r : vec) {
		std::cin >> r;
	}
}

int get_different_tile_cnt_wb_chessboard(const std::vector<std::string>& vec) {
	int dif = 0;
	char now = 'W';
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if ((r + c) % 2 == 0)
				now = 'W';
			else
				now = 'B';
			if (now != vec[r][c])
				dif++;
		}
	}
	return dif;
}
int get_different_tile_cnt_bw_chessboard(const std::vector<std::string>& vec) {
	int dif = 0;
	char now = 'W';
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if ((r + c) % 2 == 0)
				now = 'B';
			else
				now = 'W';
			if (now != vec[r][c])
				dif++;
		}
	}
	return dif;
}

std::vector<std::string> slicing_vec(const std::vector<std::string>& vec, const int& start_row, const int& start_col) {
	std::vector<std::string> res;
	for (int i = 0; i < 8; i++) {
		res.push_back(vec[start_row + i].substr(start_col, 8));
	}
	return res;
}

int main(void) {
	int row, col;
	std::cin >> row >> col;
	std::vector<std::string>board(row);
	set_board(board);
	int min_dif = 64;
	for (int r = 0; r <= row - 8; r++) {
		for (int c = 0; c <= col - 8; c++) {
			int wb_dif = get_different_tile_cnt_wb_chessboard(slicing_vec(board, r, c));
			int bw_dif = get_different_tile_cnt_bw_chessboard(slicing_vec(board, r, c));
			if (min_dif > wb_dif)
				min_dif = wb_dif;
			if (min_dif > bw_dif)
				min_dif = bw_dif;
		}
	}
	std::cout << min_dif;
	return 0;
}