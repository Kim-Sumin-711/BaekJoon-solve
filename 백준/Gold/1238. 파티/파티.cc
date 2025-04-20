#include<iostream>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<functional>

using Map = std::unordered_map<int, std::vector<std::pair<int, int>>>;
int INF = 2100000000;
void set_map(Map& town_map, int road_cnt) {
	while (road_cnt--) {
		int start, goal, cost; std::cin >> start >> goal >> cost;
		start--; goal--;
		town_map[start].push_back(std::make_pair(goal, cost));
	}
}

void get_min_time_from_start_town(Map& town_map, std::vector<int>& time_vec, const int& start, const int& town_cnt) {
	std::vector<int> times(town_cnt, INF);
	//priority_queue's third parameter -> compare function
	auto compare_pair = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second > b.second; };
	std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare_pair)> qu(compare_pair);
	times[start] = 0;
	qu.push(std::make_pair(start, 0));
	while (!qu.empty()) {
		int now = qu.top().first;
		int cost = qu.top().second;
		qu.pop();
		if (cost > times[now]) continue;
		for (auto iter = town_map[now].begin(); iter != town_map[now].end(); iter++) {
			if (times[iter->first] > cost + iter->second) {
				times[iter->first] = cost + iter->second;
				qu.push(std::make_pair(iter->first, cost + iter->second));
			}
		}
	}
	for (int i = 0; i < town_cnt; i++) {
		time_vec[i] += times[i];
	}
}

void reverse_map(Map& town_map, const int& town_cnt) {
	Map temp;
	for (int town = 0; town < town_cnt; town++) {
		for (std::pair<int, int>& road : town_map[town]) {
			temp[road.first].push_back(std::make_pair(town, road.second));
		}
	}
	town_map = temp;
}

void set_time_vec(Map& town_map, std::vector<int>& time_vec, const int& town_cnt, const int& party_town) {
	//X 기준 다른 노드까지의 최소cost를 다익쨩 알고리즘으로 계산.
	get_min_time_from_start_town(town_map, time_vec, party_town, town_cnt);
	//각 노드로부터 X까지의 최소cost를 구해야함
	//X제외 모든 노드를 시작점으로 다익쨩으로 각각 탐색하면 TLE이슈 발생함.
	//다익쨩을 노드 개수-1 만큼 돌리니까... 느려터짐
	//그래서 그래프 방향을 reverse하고 X를 시작점으로 cost를 구함
	reverse_map(town_map, town_cnt);
	get_min_time_from_start_town(town_map, time_vec, party_town, town_cnt);	
}

int get_answer(Map& town_map, const int& town_cnt, const int& party_town) {
	std::vector<int> time_vec(town_cnt, 0);
	set_time_vec(town_map, time_vec, town_cnt, party_town);
	int ans = *std::max_element(time_vec.begin(), time_vec.end());
	return ans;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int town_cnt, road_cnt, party_town;
	std::cin >> town_cnt >> road_cnt >> party_town;
	party_town--;
	Map town_map;
	set_map(town_map, road_cnt);
	std::cout << get_answer(town_map, town_cnt, party_town);
	return 0;
}