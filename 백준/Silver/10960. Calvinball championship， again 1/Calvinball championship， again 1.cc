#include<iostream>
#include<vector>
int main(void) {
	int player_cnt, dislike_cnt; std::cin >> player_cnt >> dislike_cnt;
	std::vector<std::vector<bool>> dislike_players(player_cnt + 1, std::vector<bool>(player_cnt+1,false));
	while (dislike_cnt--) {
		int a, b; std::cin >> a >> b;
		dislike_players[a][b] = true;
		dislike_players[b][a] = true;
	}
	std::vector<std::vector<short>> team_vec;
	std::vector<bool> selected(player_cnt + 1, false);
	for (short p = 1; p < player_cnt+1; p++) {
		if (selected[p] == false) {
			selected[p] = true;
			std::vector<short> team = { p };
			for (short p2 = 1; p2 < player_cnt + 1; p2++) {
				if (selected[p2] == false) {
					bool can_you_join_my_team = true;
					for (short current_team_member : team) {
						if (dislike_players[current_team_member][p2] == true) {
							can_you_join_my_team = false;
							break;
						}
					}
					if (can_you_join_my_team == true) {
						selected[p2] = true;
						team.push_back(p2);
					}
				}
			}
			team_vec.push_back(team);
		}
	}
	std::cout << team_vec.size() << "\n";
	for (const std::vector<short>& team : team_vec) {
		for (const short& teammate : team) {
			std::cout << teammate << ' ';
		}
		std::cout << "\n";
	}

	return 0;
}