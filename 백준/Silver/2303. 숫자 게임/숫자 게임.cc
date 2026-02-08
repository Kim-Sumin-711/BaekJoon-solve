#include<iostream> 
#include<vector>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int player_cnt; std::cin >> player_cnt;
	int winner=0, winner_score=0;
	for(int p = 1; p < player_cnt+1;p++) {
		std::vector<short> cards(5); std::cin >> cards[0] >> cards[1] >> cards[2] >> cards[3] >> cards[4];
		int score = 0;
		if (score < (cards[0] + cards[1] + cards[2]) % 10) score = (cards[0] + cards[1] + cards[2]) % 10;
		if (score < (cards[0] + cards[1] + cards[3]) % 10) score = (cards[0] + cards[1] + cards[3]) % 10;
		if (score < (cards[0] + cards[1] + cards[4]) % 10) score = (cards[0] + cards[1] + cards[4]) % 10;
		if (score < (cards[0] + cards[2] + cards[3]) % 10) score = (cards[0] + cards[2] + cards[3]) % 10;
		if (score < (cards[0] + cards[2] + cards[4]) % 10) score = (cards[0] + cards[2] + cards[4]) % 10;
		if (score < (cards[0] + cards[3] + cards[4]) % 10) score = (cards[0] + cards[3] + cards[4]) % 10;
		if (score < (cards[1] + cards[2] + cards[3]) % 10) score = (cards[1] + cards[2] + cards[3]) % 10;
		if (score < (cards[1] + cards[2] + cards[4]) % 10) score = (cards[1] + cards[2] + cards[4]) % 10;
		if (score < (cards[1] + cards[3] + cards[4]) % 10) score = (cards[1] + cards[3] + cards[4]) % 10;
		if (score < (cards[2]+ cards[3] + cards[4]) % 10) score = (cards[2] + cards[3] + cards[4]) % 10;

		if (winner_score <= score) {
			winner_score = score;
			winner = p;
		}
	}
	std::cout << winner;
	return 0;
}