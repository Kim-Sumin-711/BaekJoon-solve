#include<iostream>
#include<vector>
class Sudoku
{
public:
	Sudoku();
	void set_rows_num(void);
	void set_cols_num(void);
	void set_boxs_num(void);
	const std::vector<std::vector<bool>>& get_rows_num(void) const;
	const std::vector<std::vector<bool>>& get_cols_num(void) const;
	const std::vector<std::vector<bool>>& get_boxs_num(void) const;
	bool alter_a_value_of_sdk_body(int, int, short, bool = false);
	bool fill_if_it_is_forced_movement_subject(int, int);
	short get_body_elem(int, int);
	void print_the_body(void) const;

private:
	std::vector<std::vector<short>> body = 
		std::vector<std::vector<short>>(9, std::vector<short>(9, 0));

	std::vector<std::vector<bool>> rows_num = 
		std::vector<std::vector<bool>>(9, std::vector<bool>(10, false));

	std::vector<std::vector<bool>> cols_num =
		std::vector<std::vector<bool>>(9, std::vector<bool>(10, false));

	std::vector<std::vector<bool>> boxs_num =
		std::vector<std::vector<bool>>(9, std::vector<bool>(10, false));
};

Sudoku::Sudoku() {
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			char temp;
			std::cin >> temp;
			this->body[r][c] = temp - '0';
		}
	}
}

void Sudoku::set_rows_num(void) {
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			if (this->body[r][c] != 0) {
				this->rows_num[r][this->body[r][c]] = true;
			}
		}
	}
}
void Sudoku::set_cols_num(void) {
	for (int c = 0; c < 9; c++) {
		for (int r = 0; r < 9; r++) {
			if (this->body[r][c] != 0) {
				this->cols_num[c][this->body[r][c]] = true;
			}
		}
	}
}

void Sudoku::set_boxs_num(void) {
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			if (this->body[r][c] != 0) {
				this->boxs_num[r/3*3+c/3][this->body[r][c]] = true;
			}
		}
	}
}
const std::vector<std::vector<bool>>& Sudoku::get_rows_num(void) const {
	return this->rows_num;
}
const std::vector<std::vector<bool>>& Sudoku::get_cols_num(void) const {
	return this->cols_num;
}
const std::vector<std::vector<bool>>& Sudoku::get_boxs_num(void) const {
	return this->boxs_num;
}

bool Sudoku::alter_a_value_of_sdk_body(int row, int col, short val, bool correct_check_needed) {
	if (correct_check_needed == false) {
		this->rows_num[row][this->body[row][col]] = false;
		this->cols_num[col][this->body[row][col]] = false;
		this->boxs_num[row / 3 * 3 + col / 3][this->body[row][col]] = false;
		this->body[row][col] = val;
		if (val != 0) {
			this->rows_num[row][val] = true;
			this->cols_num[col][val] = true;
			this->boxs_num[row / 3 * 3 + col / 3][val] = true;
		}
		return true;
	}
	else {
		if (this->rows_num[row][val] == false && this->cols_num[col][val] == false && this->boxs_num[row / 3 * 3 + col / 3][val] == false) {
			this->rows_num[row][this->body[row][col]] = false;
			this->cols_num[col][this->body[row][col]] = false;
			this->boxs_num[row / 3 * 3 + col / 3][this->body[row][col]] = false;
			this->body[row][col] = val;
			if (val != 0) {
				this->rows_num[row][val] = true;
				this->cols_num[col][val] = true;
				this->boxs_num[row / 3 * 3 + col / 3][val] = true;
			}
			return true;
		}
		else
			return false;
	}
}

bool Sudoku::fill_if_it_is_forced_movement_subject(int row, int col) {
	bool forced_movement_subject = false;
	short forced_value = 0;
	for (int num = 1; num < 10; num++) {
		if (this->rows_num[row][num] == false && this->cols_num[col][num] == false && this->boxs_num[row / 3 * 3 + col / 3][num] == false) {
			if (forced_movement_subject == true) {
				forced_movement_subject = false;
				break;
			}
			else {
				forced_movement_subject = true;
				forced_value = num;
			}
		}
	}
	if (forced_movement_subject == true) {
		this->alter_a_value_of_sdk_body(row, col, forced_value);
		return true;
	}
	else return false;
}

short Sudoku::get_body_elem(int row, int col) {
	return this->body[row][col];
}

void Sudoku::print_the_body(void) const {
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			std::cout << this->body[r][c] << ' ';
		}
		std::cout << "\n";
	}
}

//fill the cells that have only one answer
void do_forced_move(Sudoku& sdk) {
	bool there_is_forced_movement = true;
	while (there_is_forced_movement) {
		there_is_forced_movement = false;
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				if (sdk.get_body_elem(r, c) == 0) {
					bool altered = sdk.fill_if_it_is_forced_movement_subject(r, c);
					if (altered) there_is_forced_movement = true;
				}
			}
		}
	}
}

bool backtracking_sol(Sudoku& sdk) {
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			if (sdk.get_body_elem(r, c) == 0) {
				for (int num = 1; num < 10; num++) {
					bool is_it_correct_num = sdk.alter_a_value_of_sdk_body(r, c, num, true);
					if (is_it_correct_num == false) {
						sdk.alter_a_value_of_sdk_body(r, c, 0, false);
						continue;
					}
					else {
						bool is_it_answer_num = backtracking_sol(sdk);
						if (is_it_answer_num == false) {
							sdk.alter_a_value_of_sdk_body(r, c, 0, false);
							continue;
						}
						else {
							return true;
						}
					}
				}
				if (sdk.get_body_elem(r, c) == 0) return false;
			}

		}
	}
	return true;
}



int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	Sudoku sdk;
	sdk.set_rows_num();
	sdk.set_cols_num();
	sdk.set_boxs_num();
	do_forced_move(sdk);
	backtracking_sol(sdk);
	sdk.print_the_body();
	return 0;
}