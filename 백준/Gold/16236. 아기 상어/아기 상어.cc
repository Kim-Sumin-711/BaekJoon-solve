#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using Matrix = std::vector<std::vector<int>>;

//우리의 물고기를 class로 만들어서 관리.
//이차원 배열에 직접 우리 물고기 위치 표시하면서 다니면 매우 복잡할 것 같아서 만듦.
class Fish
{
public:
	Fish(int, int);
	int get_size(void);
	void eat_feed(void);
	void change_position(int, int);
	std::pair<int, int> get_position(void);

private:
	std::pair<int, int> position;
	int size = 2;
	int eaten_fishes = 0;
};

Fish::Fish(int x, int y) {
	this->position = { x,y };
}

int Fish::get_size(void) {
	return this->size;
}

void Fish::eat_feed(void) {
	this->eaten_fishes++;
	if (this->eaten_fishes == this->size) {
		this->eaten_fishes = 0;
		this->size++;
	}
}

void Fish::change_position(int x, int y) {
	this->position = { x,y };
}

std::pair<int,int> Fish::get_position(void) {
	return this->position;
}

void set_space(Matrix& space, Fish& fish) {
	int fish_size;
	for (int i = 0; i < space.size(); i++) {
		for (int j = 0; j < space.size(); j++) {
			std::cin >> fish_size;
			if (fish_size == 9) {
				fish.change_position(i, j);
				space[i][j] = 0;
			}
			else if (fish_size != 0) {
				space[i][j] = fish_size;
			}
			
		}
	}
}

bool correct_position(const std::pair<int, int>& position, int size) {
	if (position.first < 0 || position.first >= size) {
		return false;
	}
	if (position.second < 0 || position.second >= size) {
		return false;
	}
	return true;
}

//std::pair<int,int>를 unordered set에 저장할 수 없기 떄문에
//수동으로 해시화하여 하나의 int값으로 만들어서 저장한다.
bool not_visited(const std::unordered_set<int>& visit, const std::pair<int, int>& pos) {
	int hash_val = pos.first * 20 + pos.second;
	return visit.find(hash_val) == visit.end();
}

void save_pos_in_visit(std::unordered_set<int>& visit, const std::pair<int, int>& pos) {
	int hash_val = pos.first * 20 + pos.second;
	visit.insert(hash_val);
}

//bfs로 찾자.
//거리별로 찾을 것이기에, 원래 있던 원소개수만큼 pop push 반복
bool find_and_eat_feeds(Fish& our_fish, Matrix& space, int& time) {
	int dist = 0;
	std::queue<std::pair<int, int>> bfs_queue;
	bfs_queue.push(our_fish.get_position());
	std::unordered_set<int> visit;
	save_pos_in_visit(visit, bfs_queue.front());
	bool find_feed = false;
	std::vector<std::pair<int, int>> direction = { {-1,0},{1,0},{0,-1},{0,1} };
	std::vector<std::pair<int, int>> feeds_vec;
	while (!find_feed && !bfs_queue.empty()) {
		dist++;
		int loop = bfs_queue.size();
		while (loop--) {
			std::pair<int, int> now = bfs_queue.front();
			bfs_queue.pop();
			for (std::pair<int, int> move : direction) {
				if (correct_position({ now.first + move.first,now.second + move.second }, space.size())) {
					std::pair<int, int> next = { now.first + move.first, now.second + move.second };
					if (space[next.first][next.second] != 0) {
						if (!not_visited(visit, next)) continue;
						//yaml feed >_<
						if (space[next.first][next.second] < our_fish.get_size()) {
							find_feed = true;
							feeds_vec.push_back(next);
							save_pos_in_visit(visit, next);
						}
						else if (space[next.first][next.second] == our_fish.get_size()) {
							bfs_queue.push(next);
							save_pos_in_visit(visit, next);
						}
					}
					else {
						if (not_visited(visit, next)) {
							bfs_queue.push(next);
							save_pos_in_visit(visit, next);
						}
						else continue;
					}
				}
			}
		}
	}
	if (find_feed == false) return false;
	else {
		if (feeds_vec.size() > 1) {
			std::pair<int, int> best_feed = feeds_vec[0];
			for (int i = 1; i < feeds_vec.size(); i++) {
				if (best_feed.first > feeds_vec[i].first) {
					best_feed = feeds_vec[i];
				}
				else if (best_feed.first == feeds_vec[i].first) {
					if (best_feed.second > feeds_vec[i].second) {
						best_feed = feeds_vec[i];
					}
				}
			}
			our_fish.change_position(best_feed.first, best_feed.second);
			our_fish.eat_feed();
			space[best_feed.first][best_feed.second] = 0;
			time += dist;
			return true;
		}
		else {
			our_fish.change_position(feeds_vec[0].first, feeds_vec[0].second);
			our_fish.eat_feed();
			space[feeds_vec[0].first][feeds_vec[0].second] = 0;
			time += dist;
			return true;
		}
	}
}

//거리마다 먹을 수 있는 물고기 탐지.(여기서 갈 수 있는 길만 감)
//같은 거리에 물고기 복수 존재시, 우선순위 계산 후 먹을 물고기 하나 결정.
// 먹을 물고기까지의 거리를 알고 있으므로, 시간 계산은 수월.
//더이상 먹을 수 있는 물고기가 없거나, 있더라도 도달할 수 없는 경우
// find_and_eat_feeds함수 같은데서 nowaytofeeds를 true로 만듦.
//그러면 while문 종료되고 time을 출력.
void sol(Fish& our_fish, Matrix& space) {
	int time = 0; bool no_feeds = false;
	while (!no_feeds) {
		no_feeds = !find_and_eat_feeds(our_fish, space, time);
	}
	std::cout << time;
}


int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int space_size;
	std::cin >> space_size;
	Matrix space(space_size, std::vector<int>(space_size));
	Fish our_cute_gorgeous_beautiful_kawaii_fish_chan(0, 0);
	set_space(space,our_cute_gorgeous_beautiful_kawaii_fish_chan);
	sol(our_cute_gorgeous_beautiful_kawaii_fish_chan, space);
	return 0;
}