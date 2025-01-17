#include<iostream>
#include<vector>
#include<queue>

bool load_move_queue(std::queue<std::vector<int>>& move_queue, const std::vector<int>& now_position, std::vector<std::pair<int, int>>& times_and_how_to_move, const int& goal) {
	int time = now_position[1], now = now_position[0];

	//sonic move
	if (now > 0 && now < goal && times_and_how_to_move[2 * now].first > time+1) {
		times_and_how_to_move[2 * now].first = time+1;
		move_queue.push({ 2 * now,time+1 });
		times_and_how_to_move[2 * now].second = now;
		if (2 * now == goal)
			return true;
	}

	//move forward
	if (now < goal && times_and_how_to_move[now + 1].first > time + 1) {
		move_queue.push({ now + 1,time + 1 });
		times_and_how_to_move[now + 1].first = time + 1;
		times_and_how_to_move[now + 1].second = now;
		if (now + 1 == goal)
			return true;
	}

	//move back
	if (now > 0 && times_and_how_to_move[now - 1].first > time + 1) {
		move_queue.push({ now - 1,time + 1 });
		times_and_how_to_move[now - 1].first = time + 1;
		times_and_how_to_move[now - 1].second = now;
		if (now - 1 == goal)
			return true;
	}

	return true;
}

void print_time_and_move_history(const std::vector<std::pair<int, int>>& times_and_how_to_move, const int& goal) {
	std::vector<int> print_vec;
	std::cout << times_and_how_to_move[goal].first << "\n";
	int now = goal;
	while (true) {
		now = times_and_how_to_move[now].second;
		if (now != -1) {
			print_vec.push_back(now);
		}
		else {
			for (int i = print_vec.size() - 1; i > -1; i--)
				std::cout << print_vec[i] << " ";
			std::cout << goal << " ";
			break;
		}
	}
}

void get_min_time_to_get_to_imoto_chan(const int& subin, const int& imoto_chan) {
	//position, time
	std::vector<int> now = { subin, 0 };
	//time and how to move
	std::vector<std::pair<int, int>> times_and_how_to_move(200000, { 2100000000, 0});
	std::queue<std::vector<int>> move_queue;
	move_queue.push(now);
	times_and_how_to_move[now[0]].first = 0;
	times_and_how_to_move[now[0]].second = -1;
	while (move_queue.size() != 0) {
		now = move_queue.front();
		move_queue.pop();
		if (now[0] == imoto_chan) {
			if (times_and_how_to_move[imoto_chan].first > now[1]) {
				times_and_how_to_move[imoto_chan].first = now[1];
				break;
			}
		}
		else
			load_move_queue(move_queue, now, times_and_how_to_move, imoto_chan);
	}
	print_time_and_move_history(times_and_how_to_move, imoto_chan);
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int subin, imoto_chan;
	std::cin >> subin >> imoto_chan;
	get_min_time_to_get_to_imoto_chan(subin, imoto_chan);
	return 0;
}