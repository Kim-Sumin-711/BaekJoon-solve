#include<iostream>
#include<queue>
#include<vector>

std::vector<std::vector<int>> get_next_move_vec(const std::vector<std::vector<bool>>& visit, const std::vector<std::vector<char>>& map, const std::vector<int>& now) {
	std::vector<std::vector<int>> position_vec;
	if (now[0] > 0) {
		if(!visit[now[0]-1][now[1]])
			position_vec.push_back({ now[0] - 1, now[1] });
	}
	if (now[0] < map.size() - 1) {
		if (!visit[now[0] + 1][now[1]])
			position_vec.push_back({ now[0] + 1,now[1] });
	}
	if (now[1] > 0) {
		if (!visit[now[0]][now[1]-1])
			position_vec.push_back({ now[0],now[1] - 1 });
	}
	if (now[1] < map[0].size() - 1) {
		if (!visit[now[0]][now[1]+1])
			position_vec.push_back({ now[0],now[1] + 1 });
	}
	return position_vec;
}


int get_friends_cnt(std::vector<std::vector<bool>>& visit, const std::vector<std::vector<char>>& map, const std::vector<int>& doyeon) {
	int friends = 0;
	std::queue<std::vector<int>> position_queue;
	position_queue.push(doyeon);

	while (position_queue.size() != 0) {
		std::vector<int>now = position_queue.front();
		position_queue.pop();
		if (visit[now[0]][now[1]])
			continue;
		visit[now[0]][now[1]] = true;
		if (map[now[0]][now[1]] == 'X')
			continue;
		else if (map[now[0]][now[1]] == 'P')
			friends++;

		std::vector<std::vector<int>> next_move_vec = get_next_move_vec(visit,map,now);
		if (next_move_vec.size() != 0) {
			for (std::vector<int> pos : next_move_vec)
				position_queue.push(pos);
		}
		next_move_vec.clear();
	}
	return friends;
}

int main(void) {
	int row, col;
	std::cin >> row >> col;
	std::vector<std::vector<bool>> visit(row, std::vector<bool>(col,false));
	std::vector<std::vector<char>> map(row, std::vector<char>(col));
	std::vector<int> doyeon(2);

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			std::cin >> map[r][c];
			if (map[r][c] == 'I') {
				doyeon[0] = r;
				doyeon[1] = c;
			}
		}
	}
	int res = get_friends_cnt(visit, map, doyeon);
	if (res == 0)
		std::cout << "TT";
	else
		std::cout << res;
	return 0;
}
