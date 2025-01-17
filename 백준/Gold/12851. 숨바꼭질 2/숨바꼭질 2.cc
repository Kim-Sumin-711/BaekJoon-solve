#include<iostream>
#include<vector>
#include<queue>

void load_move_queue(std::queue<std::vector<int>>& move_queue, const std::vector<int>& now_position, std::vector<int>& times, const int& goal) {
	int time = now_position[1], now = now_position[0];
	bool find_sol=false;

	//sonic move
	if (now > 0 && now < goal && times[2 * now] >= time+1) {
		times[2 * now] = time+1;
		move_queue.push({ 2 * now,time+1 });
		if (2 * now == goal)
			find_sol = true;
	}

	//move forward
	if (now < goal && times[now + 1] >= time + 1) {
		if (find_sol && now + 1 == goal) {
			move_queue.push({ now + 1,time + 1 });
		}
		else if(!find_sol) {
			move_queue.push({ now + 1,time + 1 });
			times[now + 1] = time + 1;
			if (now + 1 == goal)
				find_sol = true;
		}
		
	}

	//move back
	if (now > 0 && times[now - 1] >= time + 1) {
		if (find_sol && now-1 == goal) {
			move_queue.push({ now - 1,time + 1 });
		}
		else if (!find_sol) {
			move_queue.push({ now - 1,time + 1 });
			times[now - 1] = time + 1;
		}
	}
}

void get_min_time_to_get_to_imoto_chan(const int& subin, const int& imoto_chan) {
	//position, time
	std::vector<int> now = { subin, 0 };
	std::vector<int> times(200000,2100000000);
	std::queue<std::vector<int>> move_queue;
	int sol_cnt = 0;
	move_queue.push(now);
	times[now[0]] = 0;
	while (move_queue.size()!= 0) {
		now = move_queue.front();
		move_queue.pop();
		if (now[0] == imoto_chan) {
			if (times[imoto_chan] > now[1]) {
				sol_cnt=1;
				times[imoto_chan] = now[1];
			}
			else if (times[imoto_chan] == now[1])
				sol_cnt++;
		}
		else 
			load_move_queue(move_queue, now, times, imoto_chan);
	}
	std::cout << times[imoto_chan] << "\n" << sol_cnt;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int subin, imoto_chan;
	std::cin >> subin >> imoto_chan;
	get_min_time_to_get_to_imoto_chan(subin, imoto_chan);
	return 0;
}