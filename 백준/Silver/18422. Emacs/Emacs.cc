#include<iostream>
#include<vector>
#include<queue> 
using Matrix = std::vector<std::vector<char>>;

void set_picture(Matrix& picture) {
	for (std::vector<char>& each_row : picture)
		for (char& each_elem : each_row)
			std::cin >> each_elem;
}


void reload_position_queue(std::queue<std::vector<int>>& position_queue, std::vector<std::vector<bool>>& visit_vec, const std::vector<int>& now_position) {
	//up, down, left, right
	std::vector<int> dr = { -1,1,0,0 }, dc = { 0,0,-1,1 };
	int r_size = visit_vec.size(), c_size = visit_vec[0].size(), now_r = now_position[0], now_c = now_position[1];

	for (int i = 0; i < 4; i++) {
		std::vector<int> next_position = { now_r + dr[i], now_c + dc[i] };
		if (next_position[0] >= 0 && next_position[0] < r_size && next_position[1] >= 0 && next_position[1] < c_size) {
			if (!visit_vec[next_position[0]][next_position[1]]) {
				visit_vec[next_position[0]][next_position[1]] = true;
				position_queue.push(next_position);
			}
		}
	}
}

void set_visit_vec_in_a_star_rectangle_area(const Matrix& picture, const std::vector<int>& received_position, std::vector<std::vector<bool>>& visit_vec) {
	std::queue<std::vector<int>> position_vec_queue;
	position_vec_queue.push(received_position);
	visit_vec[received_position[0]][received_position[1]] = true;
	while (position_vec_queue.size() != 0) {
		std::vector<int> now_position = position_vec_queue.front();
		position_vec_queue.pop();
		if (picture[now_position[0]][now_position[1]] == '*')
			reload_position_queue(position_vec_queue, visit_vec, now_position);
	}
}

int get_rectangles_cnt_made_in_stars(const Matrix& picture, const int& row, const int& col) {
	int target_cnt = 0;
	std::vector<std::vector<bool>> visit(row, std::vector<bool>(col,false));
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			if (visit[r][c])
				continue;
			if (picture[r][c] == '.')
				visit[r][c] = true;
			else {
				target_cnt++;
				set_visit_vec_in_a_star_rectangle_area(picture, { r,c }, visit);
			}
		}
	}
	return target_cnt;
}

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int row, col;
	std::cin >> row >> col;
	Matrix picture(row, std::vector<char>(col));
	set_picture(picture);
	std::cout << get_rectangles_cnt_made_in_stars(picture, row, col);
	return 0;
}