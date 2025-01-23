#include<iostream>
#include<vector>
#include<algorithm>

void set_ch_map(std::vector<std::vector<char>>& ch_map) {
	for (std::vector<char>& each_row : ch_map) {
		for (char& ch : each_row) {
			std::cin >> ch;
		}
	}
}

bool is_good_index(const std::pair<int, int>& position, const int& r_size, const int& c_size) {
	if (position.first > -1 && position.first < r_size && position.second >-1 && position.second < c_size)
		return true;
	else
		return false;
}

void get_maximum_progress_cnt(const std::pair<int, int>& now_position, const std::vector<std::vector<char>>& ch_map, std::vector<bool>& visit, int now_cnt, int& max, const std::vector<int>& dr, const std::vector<int>& dc) {
	bool is_last_spot = true;
	for (int i = 0; i < 4; i++) {
		std::pair<int, int> next_position = { now_position.first + dr[i],now_position.second + dc[i] };
		if (is_good_index(next_position, ch_map.size(), ch_map[0].size())) {
			int tmp_index = ch_map[next_position.first][next_position.second] - 65;
			if (!visit[tmp_index]) {
				is_last_spot = false;
				visit[tmp_index] = true;
				get_maximum_progress_cnt(next_position, ch_map, visit, now_cnt + 1, max,dr,dc);
				visit[tmp_index] = false;
			}
		}
	}
	if (is_last_spot) {
		if (max < now_cnt)
			max = now_cnt;
	}
}


int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int r_size, c_size, max = 0;
	std::cin >> r_size >> c_size;
	std::vector<std::vector<char>> ch_map(r_size, std::vector<char>(c_size));
	std::vector<int> dr = { 0,1,0,-1 }, dc = { 1,0,-1,0 };
	set_ch_map(ch_map);
	std::vector<bool> visit(26, false);
	visit[(ch_map[0][0]) - 65] = true;
	get_maximum_progress_cnt({ 0,0 }, ch_map, visit, 1, max,dr,dc);
	std::cout << max;
	return 0;
}