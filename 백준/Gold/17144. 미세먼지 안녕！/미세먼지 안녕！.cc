#include<iostream>
#include<vector>

using Matrix = std::vector<std::vector<int>>;

void set_room(Matrix& room) {
	for (std::vector<int>& row : room) {
		for (int& elem : row) {
			std::cin >> elem;
		}
	}
}


void diffusion(Matrix& room, const int& garo, const int& sero) {
	Matrix temp(garo, std::vector<int>(sero, 0));
	std::vector<int> dr = { -1,1,0,0 }, dc = { 0,0,-1,1 };
	for (int r = 0; r < garo; r++) {
		for (int c = 0; c < sero; c++) {
			if (room[r][c] > 0) {
				//확산 방향 개수 계산, 확산된 미세먼지 temp에 저장
				int diffusion_cnt = 0;
				for (int i = 0; i < 4; i++) {
					if(r+dr[i] >=0 && r+dr[i] < garo && c+dc[i] >=0 && c+dc[i] < sero)
						if (room[r + dr[i]][c + dc[i]] != -1) {
							temp[r + dr[i]][c + dc[i]] += room[r][c] / 5;
							diffusion_cnt++;
						}
				}
				
				//확산 된 후 그 spot에 남아있는 미세먼지 양 계산
				room[r][c] -= (room[r][c] / 5) * diffusion_cnt;
			}
		}
	}
	//최종적으로 room에 반영
	for (int r = 0; r < garo; r++) {
		for (int c = 0; c < sero; c++) {
			room[r][c] += temp[r][c];
		}
	}
}

void push_fine_dust(Matrix& room, const int& garo, const int& sero, const std::vector<int>& cleaner_rows) {
	room[cleaner_rows[0] - 1][0] = 0; room[cleaner_rows[1] + 1][0] = 0;
	//upper part
	for (int r = cleaner_rows[0] - 2; r >=0 ; r--) {
		room[r + 1][0] = room[r][0];
		room[r][0] = 0;
	}
	for (int c = 1; c < sero; c++) {
		room[0][c - 1] = room[0][c];
		room[0][c] = 0;
	}
	for (int r = 1; r <= cleaner_rows[0]; r++) {
		room[r - 1][sero - 1] = room[r][sero - 1];
		room[r][sero - 1] = 0;
	}
	for (int c = sero - 2; c > 0; c--) {
		room[cleaner_rows[0]][c + 1] = room[cleaner_rows[0]][c];
		room[cleaner_rows[0]][c] = 0;
	}

	//bottom part
	for (int r = cleaner_rows[1] + 2; r < garo; r++) {
		room[r - 1][0] = room[r][0];
		room[r][0] = 0;
	}
	for (int c = 1; c < sero; c++) {
		room[garo - 1][c - 1] = room[garo - 1][c];
		room[garo - 1][c] = 0;
	}
	for (int r = garo - 2; r >= cleaner_rows[1]; r--) {
		room[r + 1][sero - 1] = room[r][sero - 1];
		room[r][sero - 1] = 0;
	}
	for (int c = sero - 2; c > 0; c--) {
		room[cleaner_rows[1]][c + 1] = room[cleaner_rows[1]][c];
		room[cleaner_rows[1]][c] = 0;
	}
}

void sol(Matrix& room, const int& garo, const int& sero, int time) {
	std::vector<int> air_cleaner_row;
	for (int r = 0; r < garo; r++) {
		if (room[r][0] == -1) {
			air_cleaner_row.push_back(r);
			air_cleaner_row.push_back(r + 1);
			break;
		}
	}

	while (time--) {
		diffusion(room, garo, sero);
		push_fine_dust(room, garo, sero,air_cleaner_row);
	}

	int total_fine_dust = 0;
	for (auto row_iter = room.begin(); row_iter != room.end(); row_iter++) {
		for (auto col_iter = row_iter->begin(); col_iter != row_iter->end(); col_iter++) {
			total_fine_dust += *col_iter;
		}
	}
	//공청기 -2 보정.
	std::cout << total_fine_dust + 2;
}


int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int row, col, time; std::cin >> row >> col >> time;
	Matrix room(row, std::vector<int>(col, 0));
	set_room(room);
	sol(room, row, col, time);
	return 0;
}