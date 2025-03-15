#include<iostream>
#include<vector>
#include<cmath>
int answer = 0;

class Queen {
	int row = 0;
	int col = 0;
public:
	Queen(int r, int c) {
		this->row = r;
		this->col = c;
	}
	int get_row(void) {
		return this->row;
	}
	int get_col(void) {
		return this->col;
	}
};

bool is_attacked(const std::vector<Queen>& queens, int row, int col,int queen_cnt) {
	for (int i = 0; i < queen_cnt;i++) {
		Queen queen = queens[i];
		if (queen.get_row() == row || queen.get_col() == col)
			return true;
		else if (std::abs(queen.get_row() - row) == std::abs(queen.get_col() - col))
			return true;
	}
	return false;
}

void sol_Nqueen(std::vector<Queen>& queens, int r, int N, int now_queen_cnt=0) {
	if (r == N) {
		return;
	}
	else {
		for (int col = 0; col < N; col++) {
			if (!is_attacked(queens, r, col, now_queen_cnt)) {
				if (now_queen_cnt + 1 == N) {
					answer++;
					return;
				}
				else {
					queens[now_queen_cnt] = Queen(r, col);
					sol_Nqueen(queens, r + 1, N, now_queen_cnt + 1);
				}
			}
		}
		
	}
}

int main(void) {
	int N;
	std::cin >> N;
	Queen Nothing(-1, -1);
	std::vector<Queen> queens(N, Nothing);
	sol_Nqueen(queens, 0, N);
	std::cout << answer;
	return 0;
}