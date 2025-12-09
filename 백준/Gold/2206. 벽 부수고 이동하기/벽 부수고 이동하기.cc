#include<iostream>
#include<vector>
#include<queue>
int INF = 2100000000;
using Map = std::vector<std::vector<int>>;
using dist_Map = std::vector<std::vector<std::pair<int, int>>>;

void set_map_info(Map& map_info) {
	for (std::vector<int>& row : map_info) {
		for (int& elem : row) {
			char tmp;
			std::cin >> tmp;
			elem = (int)tmp - 48;
		}
	}
}

bool correct_position(const std::vector<int>& now, int row_boundary, int col_boundary) {
	if (now[0] < 0) return false;
	if (now[1] < 0) return false;
	if (now[0] >= row_boundary) return false;
	if (now[1] >= col_boundary) return false;
	return true;
}

void load_qu(const Map& map_info, dist_Map& dist_map, std::queue<std::vector<int>>& qu, const std::vector<int>& now, int dist) {
	std::vector<std::pair<int, int>> direction_vec = { {-1,0},{1,0}, {0,-1}, {0,1} };
	for (const std::pair<int, int>& direction : direction_vec) {
		std::vector<int> next = { now[0] + direction.first, now[1] + direction.second, now[2] };
		if (!correct_position(next, map_info.size(), map_info[0].size())) continue;

		//0
		if (map_info[next[0]][next[1]] == 0) {
			if (next[2] == 0) {
				if (dist_map[next[0]][next[1]].first > dist) {
					qu.push(next);
					dist_map[next[0]][next[1]].first = dist;
				}
			}
			else {
				if (dist_map[next[0]][next[1]].second > dist) {
					qu.push(next);
					dist_map[next[0]][next[1]].second = dist;
				}
			}
		}
		//1
		else {
			if (next[2] != 0) {
				next[2]--;
				if (dist_map[next[0]][next[1]].first > dist) {
					qu.push(next);
					dist_map[next[0]][next[1]].first = dist;
				}
			}
		}
	}
}

int sol(const Map& map_info) {
	dist_Map dist_map(map_info.size(), std::vector<std::pair<int,int>>(map_info[0].size(),{INF,INF}));
	dist_map[0][0] = { 0,0 };
	std::vector<int> now = { 0,0,1 };
	std::pair<int, int> goal = { map_info.size()-1,map_info[0].size()-1 };
	std::queue < std::vector<int>> qu;
	qu.push(now);

	int dist = 1;
	while (!qu.empty()) {
		int loop = qu.size();
		while (loop--) {
			now = qu.front();
			if (now[0] == goal.first && now[1] == goal.second) return dist;
			load_qu(map_info, dist_map, qu, now, dist+1);
			qu.pop();
		}
		dist++;
	}
	return -1;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int row, col;
	std::cin >> row >> col;
	Map map_info(row, std::vector<int>(col, 0));
	set_map_info(map_info);	
	std::cout << sol(map_info);
	return 0; 
}