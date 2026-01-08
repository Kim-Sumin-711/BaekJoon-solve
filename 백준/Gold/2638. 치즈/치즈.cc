#include<iostream>
#include<vector>
#include<queue>
void set_cheese_map(std::vector<std::vector<short>>& cheese_map,int& cheese_cnt) {
	for (std::vector<short>& row : cheese_map) {
		for (short& elem : row) {
			std::cin >> elem;
			if (elem == 1) cheese_cnt++;
		}
	}
}

bool valid_pos(const std::pair<int, int>& pos, int row_size, int col_size) {
	if (pos.first < 0 || pos.first >= row_size) return false;
	if (pos.second < 0 || pos.second >= col_size) return false;
	return true;
}

//inner space == 0, cheese = 1, outside space = -1
void set_outside_air_to_minus_1(std::vector<std::vector<short>>& cheese_map) {
	std::vector<std::vector<bool>> visit(cheese_map.size(), std::vector<bool>(cheese_map[0].size(), false));
	std::queue<std::pair<int, int>> bfs_qu;
	bfs_qu.push({ 0,0 });
	visit[0][0] = true;
	std::vector<std::pair<int, int>> direction = { {-1,0},{1,0},{0,-1},{0,1} };
	while (bfs_qu.empty() == false) {
		std::pair<int, int> now;
		now = bfs_qu.front();
		bfs_qu.pop();
		if (cheese_map[now.first][now.second] != 1) {
			cheese_map[now.first][now.second] = -1;
			for (const std::pair<int, int>& move : direction) {
				if (valid_pos({ now.first + move.first, now.second + move.second }, cheese_map.size(), cheese_map[0].size())) {
					if (!visit[now.first + move.first][now.second + move.second]) {
						bfs_qu.push({ now.first + move.first,now.second + move.second });
						visit[now.first + move.first][now.second + move.second] = true;
					}
				}
			}
		}
	}
}


void sol(std::vector<std::vector<short>>& cheese_map, int cheese_cnt) {
	int time = 0;
	std::vector<std::pair<int, int>> direction = { {-1,0},{1,0},{0,-1},{0,1} };
	while (cheese_cnt != 0) {
		time++;
		for (int i = 1; i < cheese_map.size()-1; i++) {
			for (int j = 1; j < cheese_map[0].size()-1; j++) {
				if (cheese_map[i][j] == 1) {
					short cnt_of_near_outside_space = 0;
					for (const std::pair<int, int>& move : direction) {
						if (cheese_map[i + move.first][j + move.second] == -1) 
							cnt_of_near_outside_space++;
					}
					if (cnt_of_near_outside_space > 1) {
						cheese_map[i][j] = 0;
						cheese_cnt--;
					}
				}
			}

		}
		set_outside_air_to_minus_1(cheese_map);
	}
	std::cout << time;
}
 
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int row, col;
	std::cin >> row >> col;
	std::vector<std::vector<short>> cheese_map(row, std::vector<short>(col, 0));
	int cheese_cnt = 0;
	set_cheese_map(cheese_map, cheese_cnt);
	set_outside_air_to_minus_1(cheese_map);
	sol(cheese_map, cheese_cnt);
	return 0;
}