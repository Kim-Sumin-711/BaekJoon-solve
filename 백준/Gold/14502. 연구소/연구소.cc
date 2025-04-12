#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using Matrix = std::vector<std::vector<int>>;

void set_matrix(Matrix& map) {
	for (std::vector<int>& row : map) {
		for (int& elem : row) {
			std::cin >> elem;
		}
	}
}

int count_safe_area(const Matrix& map) {
	int safe_area = 0;
	for (const std::vector<int>& row : map) {
		for (const int& elem : row) {
			if (elem == 0) safe_area++;
		}
	}
	return safe_area;
}

int contagious_and_get_safe_area(Matrix map,const int& garo, const int& sero) {
	std::queue<std::pair<int, int>> position_queue;
	for (int r = 0; r < garo; r++) {
		for (int c = 0; c < sero; c++) {
			if (map[r][c] == 2)	position_queue.push(std::make_pair(r, c));
		}
	}

	std::vector<int> dr = { -1,1,0,0 }, dc = { 0,0,-1,1 };
	while (!position_queue.empty()) {
		std::pair<int, int> now = position_queue.front();
		position_queue.pop();
		for (int i = 0; i < 4; i++) {
			int row = now.first + dr[i], col = now.second + dc[i];
			if (row >= garo || row < 0 || col >= sero || col < 0) continue;
			if (map[row][col] == 0) {
				map[row][col] = 2;
				position_queue.push(std::make_pair(row, col));
			}
		}
	}
	return count_safe_area(map);
}


void sol(Matrix& map, const int& garo, const int& sero) {
	int maximum_of_safe_area = 0;
	std::vector<std::pair<int, int>> zero_spots;
	for (int r = 0; r < garo; r++) {
		for (int c = 0; c < sero; c++) {
			if (map[r][c] == 0) zero_spots.push_back(std::make_pair(r, c));
		}
	}
	std::vector<bool> permu(zero_spots.size()-3,false);
	permu.push_back(true); permu.push_back(true); permu.push_back(true);

	do {
		int wall_cnt = 0;
		std::vector<std::pair<int, int>> walls = {};
		for (int i = 0; i < permu.size(); i++) {
			if (wall_cnt == 3) break;
			if (permu[i]) {
				wall_cnt++;
				walls.push_back(zero_spots[i]);
				map[zero_spots[i].first][zero_spots[i].second] = 1;
			}
		}
		int temp = contagious_and_get_safe_area(map, garo, sero);
		if (maximum_of_safe_area < temp)
			maximum_of_safe_area = temp;
		for (int i = 0; i < 3; i++) {
			map[walls[i].first][walls[i].second] = 0;
		}
	} while (std::next_permutation(permu.begin(), permu.end()));
	std::cout << maximum_of_safe_area;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int garo, sero; std::cin >> garo >> sero;
	Matrix map(garo, std::vector<int>(sero, 0));
	set_matrix(map);
	sol(map, garo, sero);
	return 0;
}