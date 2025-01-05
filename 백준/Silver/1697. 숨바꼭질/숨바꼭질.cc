#include<iostream>
#include<vector>
#include<queue>
int min_time_for_go_to_imoto_from_soobin(const int& soobin, const int& imoto) {
	std::vector<int> visit_history(100001);
	visit_history[soobin] = 1;
	std::queue<int> position_queue;
	position_queue.push(soobin);
	int now = 0;
	while (true) {
		now = position_queue.front();
		position_queue.pop();
		if (now == imoto) {
			return visit_history[now]-1;
		}
		if (now - 1 >= 0 && visit_history[now - 1] == 0) {
			visit_history[now - 1] = visit_history[now] + 1;
			position_queue.push(now - 1);			
		}
		if (now + 1 < 100001 && visit_history[now + 1] == 0) {
			visit_history[now + 1] = visit_history[now] + 1;
			position_queue.push(now +1);
		}
		if (2 * now < 100001 && visit_history[2 * now] == 0) {
				visit_history[2 * now] = visit_history[now] + 1;
				position_queue.push(2 * now);
		}
	}
}

int main(void) {
	int soobin, imoto;
	std::cin >> soobin >> imoto;
	std::cout << min_time_for_go_to_imoto_from_soobin(soobin, imoto);
	return 0;
}