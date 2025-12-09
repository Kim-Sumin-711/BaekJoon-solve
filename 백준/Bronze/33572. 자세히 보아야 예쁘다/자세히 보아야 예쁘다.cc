#include<iostream>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	long long stu_cnt, total_time;
	std::cin >> stu_cnt >> total_time;
	long long safe_staring_time = 0;
	while (stu_cnt--) {
		long long time_limit;
		std::cin >> time_limit;
		time_limit--;
		safe_staring_time += time_limit;
	}
	if (safe_staring_time >= total_time) std::cout << "DIMI";
	else std::cout << "OUT";
	return 0;
}