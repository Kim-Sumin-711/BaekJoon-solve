#include<iostream>
#include<vector>
#include<queue> 
#include<algorithm>
void set_city_map(std::vector<std::vector<short>>& city_map, std::vector < std::pair<short, short>>& chiki_position) {
	for (int r = 0; r < city_map.size(); r++) {
		for (int c = 0; c < city_map.size(); c++) {
			std::cin >> city_map[r][c];
			if (city_map[r][c] == 2)
				chiki_position.push_back(std::make_pair(r, c));
		}
	}
}

void set_dis_vec(const std::vector<std::vector<short>>& city_map, const std::vector < std::pair<short, short>>& chiki_position, std::vector<std::vector<short>>& dis_vec) {
	for (int r = 0; r < city_map.size(); r++) {
		for (int c = 0; c < city_map.size(); c++) {
			std::vector<short>tmp;
			if (city_map[r][c] == 1) {
				for (const std::pair<short, short>& chiki : chiki_position) {
					tmp.push_back(std::abs(chiki.first - r) + std::abs(chiki.second - c));
				}
				dis_vec.push_back(tmp);
			}
		}
	}
}

int get_chiki_dis(const std::vector<std::vector<short>>& dis_vec, const std::vector<short>& select_vec) {
	int sum = 0;
	std::vector<short> tmp_dis_vec;
	for (const std::vector<short>& each_vec : dis_vec) {
		for (int i = 0; i < select_vec.size(); i++) {
			if (select_vec[i] == 1) {
				tmp_dis_vec.push_back(each_vec[i]);
			}
		}
		sum += *(std::min_element(tmp_dis_vec.begin(), tmp_dis_vec.end()));
		tmp_dis_vec.clear();
	}
	return sum;

}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int city_size, remain_chiki_cnt;
	std::cin >> city_size >> remain_chiki_cnt;
	std::vector<std::vector<short>>city_map(city_size, std::vector<short>(city_size));
	std::vector < std::pair<short, short>> chiki_position;
	std::vector<std::vector<short>>dis_vec;
	set_city_map(city_map, chiki_position);
	set_dis_vec(city_map, chiki_position, dis_vec);

	std::vector<short> select_vec(chiki_position.size());
	for (int i = (int)select_vec.size() - 1; i >= (int)select_vec.size()-remain_chiki_cnt; i--)
		select_vec[i] = 1;
	int min_sum = 2100000000;
	do {
		int now_sum = get_chiki_dis(dis_vec, select_vec);
		if (now_sum < min_sum) {
			min_sum = now_sum;
		}
	} while (std::next_permutation(select_vec.begin(), select_vec.end()));
	std::cout << min_sum;
	return 0;
}