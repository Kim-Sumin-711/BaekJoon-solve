#include<iostream>
#include<vector>
#include<unordered_map>
void set_cards(std::vector<int>& cards) {
	for (int i = 0; i < cards.size(); i++) {
		std::cin >> cards[i];
	}
}

//Finally I found it.
//Just check is it n*x shape.
//if so, n -> +1, n*x -> -1
//draw can be ignored. it is 0 point. 
void calc_the_scores(std::unordered_map<int, int>& score_map, const std::vector<int>& cards) {
	for (int p1 = 0; p1 < cards.size(); p1++) {
		if (cards[p1] == 1) {
			score_map[cards[p1]] += score_map.size() - 1;
			for (int p2 = 0; p2 < cards.size(); p2++) {
				if (p1 != p2) score_map[cards[p2]]--;
			}
			continue;
		}
		else {
			int temp = 2;
			int temp_multiple = cards[p1] * temp;
			while (temp_multiple < 1000001) {
				if (score_map.find(temp_multiple) != score_map.end()) {
					score_map[cards[p1]]++; score_map[temp_multiple]--;
				}
				temp++; temp_multiple = cards[p1] * temp;
			}
		}
		
	}
}

void cout_the_scores(const std::vector<int>& cards, std::unordered_map<int, int> & score_map) {
	for (int p = 0; p < cards.size(); p++) {
		std::cout << score_map[cards[p]] << ' ';
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int player_cnt; std::cin >> player_cnt;
	std::vector<int> cards(player_cnt);
	set_cards(cards);
	std::unordered_map<int, int> score_map;
	for (int p = 0; p < player_cnt; p++) {
		score_map.insert({ cards[p],0});
	}
	calc_the_scores(score_map, cards);
	cout_the_scores(cards, score_map);
	return 0;
}