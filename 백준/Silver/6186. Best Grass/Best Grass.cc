#include<iostream>
#include<vector>
#include<queue>
int main(void) {
	int row, col; std::cin >> row >> col;
	std::vector<std::vector<char>> map(row, std::vector<char>(col));
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			std::cin >> map[r][c];
		}
	}

	std::vector<std::vector<bool>> visit(row, std::vector<bool>(col, false));
	std::queue<std::pair<int, int>> qu;
	int bush_cnt = 0;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			if (map[r][c] == '#' && visit[r][c] == false) {
				bush_cnt++;
				visit[r][c] = true;
				qu.push({ r,c });
				while (qu.empty() == false) {
					std::pair<int, int> now = qu.front();
					qu.pop();
					if (now.first - 1 >= 0) {
						if (map[now.first - 1][now.second] == '#' && visit[now.first - 1][now.second] == false) {
							visit[now.first - 1][now.second] = true;
							qu.push({ now.first - 1,now.second });
						}
					}
					if (now.second - 1 >= 0) {
						if (map[now.first][now.second - 1] == '#' && visit[now.first][now.second - 1] == false) {
							visit[now.first][now.second - 1] = true;
							qu.push({ now.first,now.second - 1 });
						}
					}
					if (now.first + 1 < row) {
						if (map[now.first + 1][now.second] == '#' && visit[now.first + 1][now.second] == false) {
							visit[now.first + 1][now.second] = true;
							qu.push({ now.first + 1,now.second });
						}
					}
					if (now.second + 1 < col) {
						if (map[now.first][now.second + 1] == '#' && visit[now.first][now.second + 1] == false) {
							visit[now.first][now.second + 1] = true;
							qu.push({ now.first,now.second + 1 });
						}
					}
				}
			}
		}
	}
	std::cout << bush_cnt;
	return 0;
}