#include<iostream>
#include<vector>
#include<queue>

bool load_move_queue(std::queue<std::vector<int>>& move_queue, const std::vector<int>& now_position, std::vector<int>& times, const int& goal) {
	int time = now_position[1], now = now_position[0];

	//sonic move
	if (now > 0 && now < goal && times[2 * now] > time) {
		times[2 * now] = time;
		move_queue.push({ 2 * now,time });
		if (2 * now == goal)
			return true;
	}

	//move forward
	if (now < goal && times[now + 1] > time + 1) {
		move_queue.push({ now + 1,time + 1 });
		times[now + 1] = time + 1;
		if (now + 1 == goal)
			return true;
	}

	//move back
	if (now > 0 && times[now - 1] > time + 1) {
		move_queue.push({ now - 1,time + 1 });
		times[now - 1] = time + 1;
		if (now - 1 == goal)
			return true;
	}

	return true;
}

int get_min_time_to_get_to_imoto_chan(const int& subin, const int& imoto_chan) {
	//position, time
	std::vector<int> now = { subin, 0 };
	std::vector<int> times(200000,2100000000);
	std::queue<std::vector<int>> move_queue;
	move_queue.push(now);
	times[now[0]] = 0;
	while (move_queue.size()!= 0) {
		now = move_queue.front();
		move_queue.pop();
		if (now[0] == imoto_chan) {
			if(times[imoto_chan] > now[1])
				times[imoto_chan] = now[1];
		}
		else 
			load_move_queue(move_queue, now, times, imoto_chan);
	}
	return times[imoto_chan];
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int subin, imoto_chan;
	std::cin >> subin >> imoto_chan;
	std::cout << get_min_time_to_get_to_imoto_chan(subin, imoto_chan);
	return 0;
}