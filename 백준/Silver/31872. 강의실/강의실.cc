#include<iostream>
#include<vector>
#include<algorithm>
void setup_spot_vec(std::vector<int>& spot_vec) {
	for (int& spot : spot_vec)
		std::cin >> spot;
	std::sort(spot_vec.begin(), spot_vec.end());
}

void setup_dis_vec(std::vector<int>& dis_vec, const std::vector<int>& spot_vec) {
	for (int i = 0; i < spot_vec.size() - 1; i++) {
		dis_vec[i] = spot_vec[i + 1] - spot_vec[i];
	}
	dis_vec[dis_vec.size() - 1] = spot_vec[0];
	std::sort(dis_vec.begin(), dis_vec.end(), [](int a, int b) {return a > b; });
}

int get_min_time(const std::vector<int>& dis_vec, int& sonic_move_limit) {
	int time_sum=0;
	for (int i = sonic_move_limit; i < dis_vec.size();i++)
		time_sum += dis_vec[i];
	return time_sum;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int lecture_count, sonic_move_limit;
	std::cin >> lecture_count >> sonic_move_limit;
	std::vector<int>spot_vec(lecture_count);
	setup_spot_vec(spot_vec);
	std::vector<int>spot_distance(lecture_count);
	setup_dis_vec(spot_distance, spot_vec);
	std::cout << get_min_time(spot_distance, sonic_move_limit);

	return 0;
}