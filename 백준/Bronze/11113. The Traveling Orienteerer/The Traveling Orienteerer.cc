#include<iostream>
#include<vector>
#include<cmath>

void set_vec(std::vector<std::pair<double, double>>& points, int cnt) {
	while (cnt--) {
		double x, y;
		std::cin >> x >> y;
		points.push_back(std::make_pair(x, y));
	}
}

double calc_distance(const std::pair<double, double>& p1, const std::pair<double, double>& p2) {
	double dx = p1.first - p2.first;
	double dy = p1.second - p2.second;
	return std::sqrt(dx * dx + dy * dy);
}

void print_each_distance(const std::vector<std::pair<double, double>>& points, int test_case) {
	while (test_case--) {
		int route_node_cnt;
		std::cin >> route_node_cnt;
		std::vector<int> route;
		while (route_node_cnt--) {
			int temp;
			std::cin >> temp;
			route.push_back(temp);
		}
		double sum = 0;
		for (int i = 0; i < route.size() - 1; i++) {
			sum += calc_distance(points[route[i]], points[route[i + 1]]);
		}
		std::cout << std::round(sum) << "\n";
		route.clear();
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int point_cnt;
	std::cin >> point_cnt;
	std::vector<std::pair<double, double>> points;
	set_vec(points, point_cnt);
	int test_cast;
	std::cin >> test_cast;
	print_each_distance(points, test_cast);
	return 0;
}