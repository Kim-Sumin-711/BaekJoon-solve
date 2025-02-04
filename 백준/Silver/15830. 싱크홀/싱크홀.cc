#include<iostream>
#include<cmath>
double get_vertical_move_dis(const double& time) {
	return 5 * time * time;
}
int main(void) {
	double x_speed, hole_width,hole_depth, moved_distance=0, collision_time=0,tmp_dis=0;
	int collision_count = 0;
	std::cin >> x_speed >> hole_width >> hole_depth;
	collision_time = hole_width / x_speed;
	while (moved_distance != hole_depth) {
		tmp_dis = get_vertical_move_dis(collision_time);
		if (tmp_dis + moved_distance > hole_depth) {
			break;
		}
		else {
			collision_time *= 1.25;
			collision_count++;
			moved_distance += tmp_dis;
		}
	}
	std::cout << collision_count;
	return 0;
}