#include<iostream>
#include<vector>
#include<string>
#include<queue>

void set_picture(std::vector<std::vector<int>>& picture) {
	for (std::vector<int>& elem_vec : picture) {
		std::string str;
		std::cin >> str;
		for (int i = 0; i < str.size(); i++)
			elem_vec[i] = str[i];
	}
}

std::vector<std::vector<int>> get_next_spot(const std::vector<int>& now_spot, std::vector<std::vector<int>>& visit,const int& size) {
	std::vector<std::vector<int>> spot_vec;
	int row = now_spot[0];
	int col = now_spot[1];
	//up
	if (row - 1 >= 0 && visit[row - 1][col] == 0)
		spot_vec.push_back({ row - 1,col });
		
	//down
	if (row + 1 < size && visit[row + 1][col] == 0)
		spot_vec.push_back({ row + 1,col });

		
	//left
	if (col - 1 >= 0 && visit[row][col - 1] == 0) 
		spot_vec.push_back({ row,col - 1 });
		
	//right
	if (col + 1 < size && visit[row][col + 1] == 0) 
		spot_vec.push_back({ row, col + 1 });
	
		
	return spot_vec;
}


int get_RG_cluster_cnt(std::vector<std::vector<int>>picture,const int& size) {
	std::vector<std::vector<int>> visit(size, std::vector<int>(size));
	std::queue<std::vector<int>> spot_queue;
	std::vector<int> now_spot(2);
	int cluster_cnt = 0;
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (picture[r][c] == 'R' || picture[r][c] == 'G') {
				if (visit[r][c] == 0) {
					cluster_cnt++;
					spot_queue.push({ r,c });
					visit[r][c] = 1;
					while (spot_queue.size() != 0) {
						now_spot = spot_queue.front();
						spot_queue.pop();
						for (const std::vector<int>& spot : get_next_spot(now_spot, visit, size)) {
							if (picture[spot[0]][spot[1]] == 'R' || picture[spot[0]][spot[1]] == 'G') {
								spot_queue.push(spot);
								visit[spot[0]][spot[1]] = 1;
							}
						}
					}
				}
			}
			else {
				if (visit[r][c] == 0) {
					cluster_cnt++;
					spot_queue.push({ r,c });
					visit[r][c] = 1;
					while (spot_queue.size() != 0) {
						now_spot = spot_queue.front();
						spot_queue.pop();
						for (const std::vector<int>& spot : get_next_spot(now_spot, visit, size)) {
							if (picture[spot[0]][spot[1]] == 'B') {
								spot_queue.push(spot);
								visit[spot[0]][spot[1]] = 1;
							}
						}
					}
				}
			}
		}
	}
	return cluster_cnt;
}

int get_R_or_G_cluster_cnt(std::vector<std::vector<int>>picture, const int& size) {
	std::vector<std::vector<int>> visit(size, std::vector<int>(size));
	std::queue<std::vector<int>> spot_queue;
	std::vector<int> now_spot(2);
	int cluster_cnt = 0;
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (visit[r][c] == 0) {
				cluster_cnt++;
				spot_queue.push({ r,c });
				visit[r][c] = 1;
				while (spot_queue.size() != 0) {
					now_spot = spot_queue.front();
					spot_queue.pop();
					for (const std::vector<int>& spot : get_next_spot(now_spot, visit, size)) {
						if (picture[spot[0]][spot[1]] == picture[r][c]) {
							spot_queue.push(spot);
							visit[spot[0]][spot[1]] = 1;
						}
					}
				}
			}
		}
	}
	return cluster_cnt;
}

int main(void) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int size;
	std::cin >> size;
	std::vector<std::vector<int>>picture(size, std::vector<int>(size));
	set_picture(picture);
	std::cout << get_R_or_G_cluster_cnt(picture, size) << " ";
	std::cout << get_RG_cluster_cnt(picture, size);
	return 0;
}