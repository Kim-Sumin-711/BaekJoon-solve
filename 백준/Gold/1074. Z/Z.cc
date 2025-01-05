#include<iostream>
#include<vector>
#include<cmath>


bool is_in(const int& start_row, const int& end_row, const int& start_col, const int& end_col, const int& target_r, const int& target_c) {
	if (start_row <= target_r && end_row > target_r) {
		if (start_col <= target_c && end_col > target_c) {
			return true;
		}
	}
	return false;
}

void find_res(int& res, const int& start_row, const int& end_row, const int& start_col, const int& end_col, const int& N, const int& start_val,const int& target_r, const int& target_c) {
	if (N >= 2) {
		if(is_in(start_row, (start_row + end_row) / 2, start_col, (start_col + end_col) / 2, target_r, target_c))
			find_res(res, start_row, (start_row+end_row) / 2, start_col, (start_col+end_col) / 2, N - 1, start_val,target_r,target_c);
		if(is_in(start_row, (start_row + end_row) / 2, (start_col + end_col) / 2, end_col, target_r, target_c))
			find_res(res, start_row, (start_row + end_row) / 2, (start_col + end_col) / 2, end_col, N - 1, start_val + (int)(pow(4, N - 1)), target_r, target_c);
		if(is_in((start_row + end_row) / 2, end_row, start_col, (start_col + end_col) / 2, target_r, target_c))
			find_res(res, (start_row + end_row) / 2, end_row, start_col, (start_col + end_col) / 2, N - 1, start_val + (int)(pow(4, N - 1) * 2), target_r, target_c);
		if(is_in((start_row + end_row) / 2, end_row, (start_col + end_col) / 2, end_col, target_r, target_c))
			find_res(res, (start_row + end_row) / 2, end_row, (start_col + end_col) / 2, end_col, N - 1, start_val + (int)(pow(4, N - 1) * 3), target_r, target_c);
	}
	else if(N == 1) {
		int val = start_val-1;
		for (int r = start_row; r < target_r; r++) {
			for (int c = start_col; c < end_col; c++) {
				val++;
			}
		}
		for (int c = start_col; c <= target_c; c++)
			val++;
		res = val;
	}
}

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int N, target_r, target_c;
	std::cin >> N >> target_r >> target_c;
	int res;
	find_res(res,0, (int)pow(2, N), 0, (int)pow(2, N), N, 0,target_r,target_c);
	std::cout << res;
	return 0;
}