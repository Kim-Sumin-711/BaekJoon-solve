#include<iostream>
#include<vector>
#include<algorithm>
void set_schedule(std::vector<std::pair<int, int>>& schedule) {
	for (std::pair<int, int>& each_meeting : schedule)
		std::cin >> each_meeting.first >> each_meeting.second;
}

bool compare(const std::pair<int,int>& a, const std::pair<int, int>& b) {
	if (a.second == b.second)
		return a.first <= b.first;
	else
		return a.second < b.second;
}

int get_possible_meeting_max_cnt(const std::vector<std::pair<int, int>>& schedule) {
	int start = 0, cnt = 0;
	for (const std::pair<int, int>& each_meeting : schedule) {
		if (each_meeting.first >= start) {
			start = each_meeting.second;
			cnt++;
		}
	}
	return cnt;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int size;
	std::cin >> size;
	std::vector<std::pair<int, int>> schedule(size);
	set_schedule(schedule);
	std::sort(schedule.begin(), schedule.end(), compare);
	std::cout << get_possible_meeting_max_cnt(schedule);
	return 0;
}