#include<iostream>
#include<vector>

using vec_2d = std::vector < std::vector<bool> >;

void set_jongyee(std::vector<std::vector<int>>& jongyee) {
	for (std::vector<int>& row_vec : jongyee)
		for (int& elem : row_vec)
			std::cin >> elem;
}

void get_max_sum_val(const vec_2d& block, const std::vector<std::vector<int>>& jongyee, const int& r_size, const int& c_size, int& max_val) {
	int max_sum = 0,tmp_sum = 0;
	//이게 맞나...
	for (int r = 0; r <= (r_size - block.size()); r++) {
		for (int c = 0; c <= (c_size - block[0].size()); c++) {
			for (int r_cursor = r; r_cursor < (r + block.size()); r_cursor++) {
				for (int c_cursor = c; c_cursor < (c + block[0].size()); c_cursor++) {
					if (block[r_cursor - r][c_cursor - c])
						tmp_sum += jongyee[r_cursor][c_cursor];
				}
			}
			if (tmp_sum > max_sum)
				max_sum = tmp_sum;
			tmp_sum = 0;
		}
	}
	if (max_val < max_sum)
		max_val = max_sum;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int row, col,max_val = 0;
	std::cin >> row >> col;
	std::vector<std::vector<int>> jongyee(row, std::vector<int>(col));
	set_jongyee(jongyee);
	//이게 맞나...
	vec_2d block0, block1, block2, block3, block4, block5, block6, block7, block8, block9, block10, block11, block12, block13, block14, block15, block16, block17, block18;
	block0 = { {true,true,true,true} };
	block1 = { {true,true},{true,true} };
	block2 = { {true,false},{true,false},{true,true} };
	block3 = { {false,true},{false,true},{true,true} };
	block4= { {true,true},{true,false},{true,false} };
	block5= { {true,true},{false,true},{false,true} };
	block6 = { {true,false,false},{true,true,true} };
	block7 = { {false,false,true},{true,true,true} };
	block8 = { {true,true,true},{true,false,false} };
	block9 = { {true,true,true},{false,false,true} };
	block10 = { {true,false},{true,true},{false,true} };
	block11 = { {false,true},{true,true},{true,false} };
	block12 = { {false,true,true},{true,true,false} };
	block13 = { {true,true,false},{false,true,true} };
	block14 = { {true,true,true},{false,true,false} };
	block15 = { {false,true,false},{true,true,true} };
	block16 = { {true,false},{true,true},{true,false} };
	block17 = { {false,true},{true,true},{false,true} };
	block18 = { {true},{true},{true},{true} };
	//엄...
	get_max_sum_val(block0, jongyee, row, col, max_val);
	get_max_sum_val(block1, jongyee, row, col, max_val);
	get_max_sum_val(block2, jongyee, row, col, max_val);
	get_max_sum_val(block3, jongyee, row, col, max_val);
	get_max_sum_val(block4, jongyee, row, col, max_val);
	get_max_sum_val(block5, jongyee, row, col, max_val);
	get_max_sum_val(block6, jongyee, row, col, max_val);
	get_max_sum_val(block7, jongyee, row, col, max_val);
	get_max_sum_val(block8, jongyee, row, col, max_val);
	get_max_sum_val(block9, jongyee, row, col, max_val);
	get_max_sum_val(block10, jongyee, row, col, max_val);
	get_max_sum_val(block11, jongyee, row, col, max_val);
	get_max_sum_val(block12, jongyee, row, col, max_val);
	get_max_sum_val(block13, jongyee, row, col, max_val);
	get_max_sum_val(block14, jongyee, row, col, max_val);
	get_max_sum_val(block15, jongyee, row, col, max_val);
	get_max_sum_val(block16, jongyee, row, col, max_val);
	get_max_sum_val(block17, jongyee, row, col, max_val);
	get_max_sum_val(block18, jongyee, row, col, max_val);
	std::cout << max_val;
	return 0;
}