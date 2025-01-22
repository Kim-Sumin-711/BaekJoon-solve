#include<iostream>
#include<vector>
#include<queue>


bool is_good_index(const int& index, const int& size) {
	if (index < 0 || index > size - 1)
		return false;
	return true;
}

bool is_possible_to_install(const std::pair<int, int>& pipe, const std::vector<std::vector<short>>& home_map) {
	if (home_map[pipe.first][pipe.second] == 1)
		return false;
	return true;
}

void load_queue(std::queue<std::vector<std::pair<int, int>>>& qu, const std::vector<std::pair<int, int>>& now, const std::vector<std::vector<short>>& home_map, const int& size) {
	if (now.size() == 4) {
		bool next1, next2;
		next1 = is_good_index(now[3].second + 1, size) && is_possible_to_install({ now[3].first,now[3].second + 1 }, home_map);
		next2 = is_good_index(now[3].first + 1, size) && is_possible_to_install({ now[3].first + 1,now[3].second },home_map);
		if (next1 && next2) {
			qu.push({ now[3],std::make_pair(now[3].first,now[3].second + 1) });
			qu.push({ now[3],std::make_pair(now[3].first + 1,now[3].second) });
			if (is_possible_to_install({ now[3].first + 1,now[3].second + 1 }, home_map))
				qu.push({ now[3],std::make_pair(now[3].first,now[3].second + 1),std::make_pair(now[3].first + 1,now[3].second),std::make_pair(now[3].first + 1,now[3].second + 1)});
		}
		else if(next1)
			qu.push({ now[3],std::make_pair(now[3].first,now[3].second + 1) });
		else if(next2)
			qu.push({ now[3],std::make_pair(now[3].first + 1,now[3].second) });
	}
	else {
		//sero
		if (now[0].second == now[1].second) {
			bool next1 = is_good_index(now[1].first + 1, size) && is_possible_to_install({ now[1].first + 1,now[1].second }, home_map);
			bool next2 = is_good_index(now[1].second + 1, size) && is_possible_to_install({ now[1].first,now[1].second + 1 }, home_map);
			if (next1) {
				qu.push({ now[1],std::make_pair(now[1].first + 1,now[1].second) });
				if (next2) {
					if (is_possible_to_install({ now[1].first + 1,now[1].second + 1 }, home_map))
						qu.push({ now[1],std::make_pair(now[1].first,now[1].second + 1),std::make_pair(now[1].first + 1,now[1].second),std::make_pair(now[1].first + 1,now[1].second + 1) });
				}
			}
		}
		//garo
		else {
			bool next1 = is_good_index(now[1].first + 1, size) && is_possible_to_install({ now[1].first + 1,now[1].second }, home_map);
			bool next2 = is_good_index(now[1].second + 1, size) && is_possible_to_install({ now[1].first,now[1].second + 1 }, home_map);
			if (next2) {
				qu.push({ now[1],std::make_pair(now[1].first,now[1].second+1) });
				if (next1) {
					if (is_possible_to_install({ now[1].first + 1,now[1].second + 1 }, home_map))
						qu.push({ now[1],std::make_pair(now[1].first,now[1].second + 1),std::make_pair(now[1].first + 1,now[1].second),std::make_pair(now[1].first + 1,now[1].second + 1) });
				}
			}
		}
	}

}

void get_possible_ways_cnt(const std::vector<std::vector<short>>& home_map) {
	std::vector<std::pair<int, int>> start_position = { std::make_pair(0,0), std::make_pair(0,1) };
	std::queue<std::vector<std::pair<int, int>>> pipe_queue;
	int possible_ways_cnt = 0;
	pipe_queue.push(start_position);
	while (pipe_queue.size() != 0) {
		std::vector<std::pair<int, int>> now = pipe_queue.front();
		pipe_queue.pop();
		if (now[now.size() - 1].first == home_map.size() - 1 && now[now.size() - 1].second == home_map.size() - 1)
			possible_ways_cnt++;
		load_queue(pipe_queue, now, home_map, home_map.size());
	}
	std::cout << possible_ways_cnt;
}

void set_home_map(std::vector<std::vector<short>>& home_map) {
	for (std::vector<short>& each_row : home_map) {
		for (short& elem : each_row)
			std::cin >> elem;
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int home_size;
	std::cin >> home_size;
	std::vector<std::vector<short>> home_map(home_size, std::vector<short>(home_size));
	set_home_map(home_map);
    if(home_map[home_map.size()-1][home_map.size()-1] == 1)
        std::cout<< 0;
    else
	    get_possible_ways_cnt(home_map);
	return 0;
}