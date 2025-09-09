#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using Matrix = std::vector<std::vector<char>>;

void set_box(Matrix& box) {
	for (std::vector<char>& each_row : box) {
		for (char& cell : each_row) {
			std::cin >> cell;
		}
	}
}

void get_red_and_blue_position(const Matrix& box, std::pair<int, int>& Red, std::pair<int, int>& Blue) {
	for (int r = 0; r < box.size(); r++) {
		for (int c = 0; c < box[0].size(); c++) {
			if (box[r][c] == 'R') Red = { r,c };
			if (box[r][c] == 'B') Blue = { r,c };
		}
	}
}

//0 <= x1, y1 <= 9
//0 <= created_hash <= 99
int encode_a_pair_ver(const std::pair<int, int>& a) {
	return a.first * 10 + a.second;
}

//0 <= x1, x2, y1, y2 <= 9
//0 <= hash_a, hash_b <= 99
//0 <= created_hash <= 9999
int encode_two_pair_ver(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	int hash_a = encode_a_pair_ver(a);
	int hash_b = encode_a_pair_ver(b);
	return hash_a * 100 + hash_b;
}

void save_encoded_value_in_visit_set(const std::pair<int, int>& red, const std::pair<int, int>& blue, std::unordered_set<int>& visit) {
	int hash_value = encode_two_pair_ver(red, blue);
	visit.insert(hash_value);
}

bool is_duplicated(const std::unordered_set<int>& visit, const std::pair<int, int>& red, const std::pair<int, int>& blue) {
	int hash_value = encode_two_pair_ver(red, blue);
	return visit.find(hash_value) != visit.end();
}

void move_left(std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>>& qu, const Matrix& box, std::pair<int, int> red, std::pair<int, int> blue) {
	bool red_finished = false, blue_finished = false;
	bool red_goal_in = false, blue_goal_in = false;

	//check there's any finished one
	if (box[red.first][red.second-1] == '#') red_finished = true;
	if (box[blue.first][blue.second-1] == '#') blue_finished = true;

	//red.first != blue.first
	if (red.first != blue.first) {

		bool red_goal_in = false, blue_goal_in = false;

		while (!red_finished || !blue_finished) {

			if (!red_finished && !red_goal_in) red.second -= 1;
			if (!blue_finished && !blue_goal_in) blue.second -= 1;

			//check there's any finished one
			if (box[red.first][red.second - 1] == '#') red_finished = true;
			if (box[blue.first][blue.second - 1] == '#') blue_finished = true;

			if (box[red.first][red.second] == 'O') {
				red_goal_in = true;
				red_finished = true;
			}
			if (box[blue.first][blue.second] == 'O') {
				blue_goal_in = true;
				blue_finished = true;
			}
		}
		if (blue_goal_in) return;
		else qu.push({ red,blue });

	}

	//red.first == blue.first
	else {
		bool red_goal_in = false, blue_goal_in = false;
		if (red_finished) {
			if (blue.second - 1 == red.second) blue_finished = true;
		}
		if (blue_finished) {
			if (red.second - 1 == blue.second) red_finished = true;
		}


		while (!red_finished || !blue_finished) {

			if (!red_finished && !red_goal_in) red.second -= 1;
			if (!blue_finished && !blue_goal_in) blue.second -= 1;

			//check there's any finished one
			if (box[red.first][red.second - 1] == '#') red_finished = true;
			if (box[blue.first][blue.second - 1] == '#') blue_finished = true;

			if (box[red.first][red.second] == 'O') {
				red_goal_in = true;
				red_finished = true;
			}
			if (box[blue.first][blue.second] == 'O') {
				blue_goal_in = true;
				blue_finished = true;
			}
	
			if (red_finished && !red_goal_in) {
				if (blue.second - 1 == red.second) blue_finished = true;
			}
			if (blue_finished && !blue_goal_in) {
				if (red.second - 1 == blue.second) red_finished = true;
			}
		}
		if (blue_goal_in) return;
		else qu.push({ red,blue });
	}
	return;
}

void move_right(std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>>& qu, const Matrix& box, std::pair<int, int> red, std::pair<int, int> blue) {
	bool red_finished = false, blue_finished = false;
	bool red_goal_in = false, blue_goal_in = false;

	//check there's any finished one
	if (box[red.first][red.second + 1] == '#') red_finished = true;
	if (box[blue.first][blue.second + 1] == '#') blue_finished = true;

	//red.first != blue.first
	if (red.first != blue.first) {

		bool red_goal_in = false, blue_goal_in = false;

		while (!red_finished || !blue_finished) {

			if (!red_finished && !red_goal_in) red.second += 1;
			if (!blue_finished && !blue_goal_in) blue.second += 1;

			//check there's any finished one
			if (box[red.first][red.second + 1] == '#') red_finished = true;
			if (box[blue.first][blue.second + 1] == '#') blue_finished = true;

			if (box[red.first][red.second] == 'O') {
				red_goal_in = true;
				red_finished = true;
			}
			if (box[blue.first][blue.second] == 'O') {
				blue_goal_in = true;
				blue_finished = true;
			}
		}
		if (blue_goal_in) return;
		else qu.push({ red,blue });

	}

	//red.first == blue.first
	else {
		bool red_goal_in = false, blue_goal_in = false;
		if (red_finished) {
			if (blue.second + 1 == red.second) blue_finished = true;
		}
		if (blue_finished) {
			if (red.second + 1 == blue.second) red_finished = true;
		}


		while (!red_finished || !blue_finished) {

			if (!red_finished && !red_goal_in) red.second += 1;
			if (!blue_finished && !blue_goal_in) blue.second += 1;

			//check there's any finished one
			if (box[red.first][red.second + 1] == '#') red_finished = true;
			if (box[blue.first][blue.second + 1] == '#') blue_finished = true;

			if (box[red.first][red.second] == 'O') {
				red_goal_in = true;
				red_finished = true;
			}
			if (box[blue.first][blue.second] == 'O') {
				blue_goal_in = true;
				blue_finished = true;
			}

			if (red_finished && !red_goal_in) {
				if (blue.second + 1 == red.second) blue_finished = true;
			}
			if (blue_finished && !blue_goal_in) {
				if (red.second + 1 == blue.second) red_finished = true;
			}
		}
		if (blue_goal_in) return;
		else qu.push({ red,blue });
	}
	return;
}

void move_up(std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>>& qu, const Matrix& box, std::pair<int, int> red, std::pair<int, int> blue) {
	bool red_finished = false, blue_finished = false;
	bool red_goal_in = false, blue_goal_in = false;

	//check there's any finished one
	if (box[red.first - 1][red.second] == '#') red_finished = true;
	if (box[blue.first - 1][blue.second] == '#') blue_finished = true;

	//red.second != blue.second
	if (red.second != blue.second) {

		bool red_goal_in = false, blue_goal_in = false;

		while (!red_finished || !blue_finished) {

			if (!red_finished && !red_goal_in) red.first -= 1;
			if (!blue_finished && !blue_goal_in) blue.first -= 1;

			//check there's any finished one
			if (box[red.first - 1 ][red.second] == '#') red_finished = true;
			if (box[blue.first - 1][blue.second] == '#') blue_finished = true;

			if (box[red.first][red.second] == 'O') {
				red_goal_in = true;
				red_finished = true;
			}
			if (box[blue.first][blue.second] == 'O') {
				blue_goal_in = true;
				blue_finished = true;
			}
		}
		if (blue_goal_in) return;
		else qu.push({ red,blue });

	}

	//red.second == blue.second
	else {
		bool red_goal_in = false, blue_goal_in = false;
		if (red_finished) {
			if (blue.first - 1 == red.first) blue_finished = true;
		}
		if (blue_finished) {
			if (red.first - 1 == blue.first) red_finished = true;
		}


		while (!red_finished || !blue_finished) {

			if (!red_finished && !red_goal_in) red.first -= 1;
			if (!blue_finished && !blue_goal_in) blue.first -= 1;

			//check there's any finished one
			if (box[red.first - 1][red.second] == '#') red_finished = true;
			if (box[blue.first - 1][blue.second] == '#') blue_finished = true;

			if (box[red.first][red.second] == 'O') {
				red_goal_in = true;
				red_finished = true;
			}
			if (box[blue.first][blue.second] == 'O') {
				blue_goal_in = true;
				blue_finished = true;
			}

			if (red_finished && !red_goal_in) {
				if (blue.first - 1 == red.first) blue_finished = true;
			}
			if (blue_finished && !blue_goal_in) {
				if (red.first - 1 == blue.first) red_finished = true;
			}
		}
		if (blue_goal_in) return;
		else qu.push({ red,blue });
	}
	return;
}

void move_down(std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>>& qu, const Matrix& box, std::pair<int, int> red, std::pair<int, int> blue) {
	bool red_finished = false, blue_finished = false;
	bool red_goal_in = false, blue_goal_in = false;

	//check there's any finished one
	if (box[red.first + 1][red.second] == '#') red_finished = true;
	if (box[blue.first + 1][blue.second] == '#') blue_finished = true;

	//red.second != blue.second
	if (red.second != blue.second) {

		bool red_goal_in = false, blue_goal_in = false;

		while (!red_finished || !blue_finished) {

			if (!red_finished && !red_goal_in) red.first += 1;
			if (!blue_finished && !blue_goal_in) blue.first += 1;

			//check there's any finished one
			if (box[red.first + 1][red.second] == '#') red_finished = true;
			if (box[blue.first + 1][blue.second] == '#') blue_finished = true;

			if (box[red.first][red.second] == 'O') {
				red_goal_in = true;
				red_finished = true;
			}
			if (box[blue.first][blue.second] == 'O') {
				blue_goal_in = true;
				blue_finished = true;
			}
		}
		if (blue_goal_in) return;
		else qu.push({ red,blue });

	}

	//red.second == blue.second
	else {
		bool red_goal_in = false, blue_goal_in = false;
		if (red_finished) {
			if (blue.first + 1 == red.first) blue_finished = true;
		}
		if (blue_finished) {
			if (red.first + 1 == blue.first) red_finished = true;
		}


		while (!red_finished || !blue_finished) {

			if (!red_finished && !red_goal_in) red.first += 1;
			if (!blue_finished && !blue_goal_in) blue.first += 1;

			//check there's any finished one
			if (box[red.first + 1][red.second] == '#') red_finished = true;
			if (box[blue.first + 1][blue.second] == '#') blue_finished = true;

			if (box[red.first][red.second] == 'O') {
				red_goal_in = true;
				red_finished = true;
			}
			if (box[blue.first][blue.second] == 'O') {
				blue_goal_in = true;
				blue_finished = true;
			}

			if (red_finished && !red_goal_in) {
				if (blue.first + 1 == red.first) blue_finished = true;
			}
			if (blue_finished && !blue_goal_in) {
				if (red.first + 1 == blue.first) red_finished = true;
			}
		}
		if (blue_goal_in) return;
		else qu.push({ red,blue });
	}
	return;
}

void push_next_move(std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>>& qu, const Matrix& box, const std::pair<int, int>& red, const std::pair<int, int>& blue) {
	move_left(qu, box, red, blue);
	move_right(qu, box, red, blue);
	move_up(qu, box, red, blue);
	move_down(qu, box, red, blue);
}


void move_the_box_for_red_to_escape(const Matrix& box, const std::pair<int,int>& Red, const std::pair<int,int>& Blue) {
	int movement_cnt = 0, row = box.size(), col = box[0].size();
	std::pair<int, int> goal;
	for (int r = 0; r < box.size(); r++) {
		for (int c = 0; c < box[0].size(); c++) {
			if (box[r][c] == 'O') {
				goal = { r,c };
			}
		}
	}

	std::unordered_set<int> visit;

	std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> simulation_queue;
	simulation_queue.push({ Red,Blue });

	while (movement_cnt < 11) {
		int queue_size = simulation_queue.size();
		for (int loop = 0; loop < queue_size; loop++) {
			std::pair<int, int> red = simulation_queue.front().first,
								blue = simulation_queue.front().second;
			simulation_queue.pop();
			if (is_duplicated(visit, red, blue)) continue;
			else save_encoded_value_in_visit_set(red, blue, visit);
			if (box[red.first][red.second] == 'O') {
				std::cout << movement_cnt;
				return;
			}
			push_next_move(simulation_queue, box, red, blue);
		}
		movement_cnt++;
	}
	std::cout << -1;
	return;

}

void sol(const Matrix& box, const int row, const int col) {
	std::pair<int, int> Red_position, Blue_position;
	get_red_and_blue_position(box, Red_position, Blue_position);
	move_the_box_for_red_to_escape(box, Red_position, Blue_position);
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int row, col;
	std::cin >> row >> col;
	Matrix box(row, std::vector<char>(col,'a'));
	set_box(box);
	sol(box, row, col);
	return 0;
}