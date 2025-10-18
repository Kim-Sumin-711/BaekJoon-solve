#include<iostream>
#include<queue>
int main(void) {
	int connect_cnt;
	std::cin >> connect_cnt;
	connect_cnt--;
	int now_connected_phone, next_connected_phone, battery_usage = 2, current_usage_log = 2;
	std::cin >> now_connected_phone;
	while (connect_cnt--) {
		std::cin >> next_connected_phone;
		if (now_connected_phone == next_connected_phone) {
			if (current_usage_log == 0) {
				battery_usage += 2;
				current_usage_log = 2;
			}
			else {
				battery_usage += current_usage_log * 2;
				current_usage_log *= 2;
			}
		}
		else {
			battery_usage += 2;
			current_usage_log = 2;
		}
		if (battery_usage >= 100) {
			battery_usage = 0;
			current_usage_log = 0;
		}
		now_connected_phone = next_connected_phone;
	}
	std::cout << battery_usage;
	return 0;
}