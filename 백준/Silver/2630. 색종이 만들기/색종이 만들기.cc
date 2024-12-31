#include<iostream>
#include<vector>

//reference : https://agandi.tistory.com/22

std::vector<int> vecSlice(const std::vector<int>& vec, const int& a, const int& b) {
	return std::vector<int>(vec.begin() + a, vec.begin() + b);
}

std::vector<std::vector<int>> vecSlice2D(const std::vector<std::vector<int>>& vec, const int& r1, const int& r2, const int& c1, const int& c2) {
	std::vector<std::vector<int>> res(r2-r1);
	for (int row = r1; row < r2; row++)
		res[row-r1] = (vecSlice(vec[row], c1, c2));
	return res;
}

std::vector<int> sum_vec_and_save_on_vec1 (std::vector<int>& vec1, const std::vector<int>& vec2) {
	for (int i = 0; i < vec1.size(); i++)
		vec1[i] += vec2[i];
	return vec1;
}

void set_map(std::vector<std::vector<int>>& map, const int& size) {
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++)
			std::cin >> map[r][c];
	}
}

//blue 1, white 0, mixed -1
int is_only_one_color(const std::vector<std::vector<int>>& map,const int& row,const int&col, const int& size) {
	int blue=0, white=0;
	for (int r = row; r < row+size; r++) {
		for (int c = col; c < col+size; c++) {
			if (map[r][c] == 1)
				blue++;
			else
				white++;
			if (blue != 0 && white != 0)
				return -1;
		}
	}
	if (white == 0)
		return 1;
	else
		return 0;
}

std::vector<int> get_white_and_blue_paper_cnt(const std::vector<std::vector<int>>& map, const int& div_size) {
	std::vector<int> color_cnt(2);
	for (int r = 0; r < map.size(); r += div_size) {
		for (int c = 0; c < map.size(); c += div_size) {
			int what_color = is_only_one_color(map, r, c, div_size);
			switch (what_color) {
			case -1:
				if (div_size/2 == 0)
					break;
				sum_vec_and_save_on_vec1(color_cnt,get_white_and_blue_paper_cnt(vecSlice2D(map, r, r + div_size, c, c + div_size),div_size/2));
				break;
			case 0:
				color_cnt[0]++;
				break;
			case 1:
				color_cnt[1]++;
				break;
			}
		}
	}
	return color_cnt;
}

void print_vec(const std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << "\n";
}
int main(void) {
	int size;
	std::cin >> size;
	std::vector<std::vector<int>>jongyee(size,std::vector<int>(size));
	set_map(jongyee, size);
	int tmp = is_only_one_color(jongyee, 0, 0, size);
	if (tmp != -1) {
		if (tmp == 1)
			std::cout << "0\n1";
		else
			std::cout << "1\n0";
		return 0;
	}
	print_vec(get_white_and_blue_paper_cnt(jongyee, size/2));
	return 0;
}