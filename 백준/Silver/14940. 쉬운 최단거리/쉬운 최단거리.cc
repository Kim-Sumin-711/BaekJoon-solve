#include<iostream>
#include<vector>
#include<queue>

std::vector<int> set_jido_and_get_target_spot(std::vector<std::vector<int>>& jido,const int& sero, const int& garo) {
	std::vector<int> target_spot(2);
	for (int r = 0; r < sero; r++) {
		for (int c = 0; c < garo; c++) {
			std::cin >> jido[r][c];
			if (jido[r][c] == 2)
				target_spot = { r,c };
		}
	}
	return target_spot;
}

//jido = 1 and visit = -1 -> next_spot, jido = 0 -> visit = 0 and not next_spot
std::vector<std::vector<int>> get_next_spot_vec(const std::vector<std::vector<int>>& jido, const std::vector<int>& target_spot, std::vector<std::vector<int>>& visit_hitory,const int& sero, const int& garo) {
	std::vector<std::vector<int>> res_vec;
	//up
	if (target_spot[0] - 1 >= 0 && visit_hitory[target_spot[0] - 1][target_spot[1]] == -1) {
		if (jido[target_spot[0] - 1][target_spot[1]] == 1) {
			res_vec.push_back({ target_spot[0] - 1,target_spot[1] });
		}
		else if (jido[target_spot[0] - 1][target_spot[1]] == 0) {
			visit_hitory[target_spot[0] - 1][target_spot[1]] = 0;
		}
	}
		
	//down
	if (target_spot[0] + 1 < sero && visit_hitory[target_spot[0] + 1][target_spot[1]] == -1) {
		if (jido[target_spot[0] + 1][target_spot[1]] == 1) {
			res_vec.push_back({ target_spot[0] + 1,target_spot[1] });
		}
		else if (jido[target_spot[0] + 1][target_spot[1]] == 0) {
			visit_hitory[target_spot[0] + 1][target_spot[1]] = 0;
		}
	}
		
	//left
	if (target_spot[1] - 1 >= 0 && visit_hitory[target_spot[0]][target_spot[1] - 1] == -1) {
		if (jido[target_spot[0]][target_spot[1] - 1] == 1) {
			res_vec.push_back({ target_spot[0],target_spot[1] - 1 });
		}
		else if (jido[target_spot[0]][target_spot[1] - 1] == 0) {
			visit_hitory[target_spot[0]][target_spot[1] - 1] = 0;
		}
	}
	//right
	if (target_spot[1] + 1 < garo && visit_hitory[target_spot[0]][target_spot[1] + 1] == -1) {
		if (jido[target_spot[0]][target_spot[1] + 1] == 1) {
			res_vec.push_back({ target_spot[0],target_spot[1] + 1 });
		}
		else if (jido[target_spot[0]][target_spot[1] + 1] == 0) {
			visit_hitory[target_spot[0]][target_spot[1] + 1] = 0;
		}
	}
	return res_vec;
}

void print_2D_vec(const std::vector<std::vector<int>>& vec) {
	for (const std::vector<int>& elem_vec : vec) {
		for (const int& elem : elem_vec) {
			std::cout << elem << " ";
		}
			
		std::cout << "\n";
	}
}

void sol(const std::vector<std::vector<int>>& jido, const int& sero, const int& garo,const std::vector<int>& target_spot) {
	//-1 : not visit, 0 : not access spot, others : already visited
	std::vector<std::vector<int>> visit_history(sero, std::vector<int>(garo,-1));
	std::queue<std::vector<int>> spot_queue;
	spot_queue.push(target_spot);
	visit_history[target_spot[0]][target_spot[1]] = 0;
	while (spot_queue.size() != 0) {
		std::vector<int> now_spot = spot_queue.front();
		spot_queue.pop();
		std::vector<std::vector<int>> next_spots = get_next_spot_vec(jido,now_spot,visit_history,sero,garo);
		for (const std::vector<int>& next_spot : next_spots) {
			visit_history[next_spot[0]][next_spot[1]] = visit_history[now_spot[0]][now_spot[1]] + 1;
			spot_queue.push(next_spot);
		}
		next_spots.clear();
	}
	for (int r = 0; r < sero;r++) {
		for (int c = 0; c < garo; c++) {
			if (visit_history[r][c] == -1 && jido[r][c] == 0)
				visit_history[r][c] = 0;
		}
	}

	print_2D_vec(visit_history);
}

int main(void) {
	int sero, garo;
	std::cin >> sero >> garo;
	std::vector<std::vector<int>> jido(sero, std::vector<int>(garo));
	std::vector<int>target_spot = set_jido_and_get_target_spot(jido,sero,garo);
	sol(jido, sero, garo, target_spot);
	return 0;
} 