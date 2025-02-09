#include<iostream>
#include<vector>
using Char_Metrix = std::vector<std::vector<char>>;

//rs : row_start, cs : col_start
void set_stars(Char_Metrix& print_area, int rs, int cs, int N) {
	if (N == 3) {
		//  *  
		// * * 
		//*****
		print_area[rs][cs+2] = '*';
		print_area[rs + 1][cs + 1] = '*';
		print_area[rs + 1][cs + 3] = '*';
		for (int i = 0; i < 5; i++)
			print_area[rs + 2][cs + i] = '*';

	}
	else {
		int tmp = N / 2;
		set_stars(print_area, rs, cs + tmp, tmp);
		set_stars(print_area, rs + tmp, cs, tmp);
		set_stars(print_area, rs + tmp, cs + N, tmp);
	}
}

void print_stars(const Char_Metrix& vec) {
	for (const std::vector<char>& each_row : vec) {
		for (const char& elem : each_row)
			std::cout << elem;
		std::cout << "\n";
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cout.tie(0);
	int N;
	std::cin >> N;
	Char_Metrix print_area(N, std::vector<char>(N * 2 - 1, ' '));
	set_stars(print_area, 0, 0, N);
	print_stars(print_area);
	return 0;
}