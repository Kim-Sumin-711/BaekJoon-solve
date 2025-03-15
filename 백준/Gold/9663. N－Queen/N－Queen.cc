#include<iostream>
#include<vector>
#include<cmath>

//N개의 퀸을 N*N보드판에 배치해야 하므로
//모든 행에 각각 하나씩 배치해야만 정답임.
//한 행에 하나씩

int answer = 0;

class Queen {
	int row = 0;
	int col = 0;
public:
	Queen(int r, int c) {
		this->row = r;
		this->col = c;
	}
	int get_row(void) const {
		return this->row;
	}
	int get_col(void) const {
		return this->col;
	}
};

bool is_attacked(const std::vector<Queen>& queens, int row, int col) {
	for (int i = 0; i < row ;i++) {
		const Queen& queen = queens[i];
		//한 행에 하나씩만 배치하도록 설계했으니 getrow와 row비교할 필요는 없음.
		if (queen.get_col() == col)
			return true;
		else if (std::abs(queen.get_row() - row) == std::abs(queen.get_col() - col))
			return true;
	}
	return false;
}

void sol_Nqueen(std::vector<Queen>& queens, int r, int N) {
	if (r == N) {
		answer++;
		return;
	}
	else {
		for (int col = 0; col < N; col++) {
			if (!is_attacked(queens, r, col)) {
				queens[r] = Queen(r, col);
				sol_Nqueen(queens, r + 1, N);
				//공격 받고 있지 않은 경우 위치 정보를 queens에 저장하고
				//row를 1증가시킴. N이 되면 전부 하나씩 배치 성공했다는 의미.
			}
			//공격받고 있는 경우 그 칸은 고려할 필요가 없음. 백트래킹.
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