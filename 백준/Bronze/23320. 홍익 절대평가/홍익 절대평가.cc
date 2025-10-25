#include<iostream>
#include<vector>
int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int stu_cnt;
	std::cin >> stu_cnt;
	std::vector<int>scores(stu_cnt);
	int sangdae_percent, A_score;
	for (int& score : scores) std::cin >> score;
	std::cin >> sangdae_percent >> A_score;

	int sangdae_A = 0, meet_A_score = 0;
	sangdae_A = stu_cnt * sangdae_percent / 100;
	for (int score : scores) {
		if (score >= A_score) meet_A_score++;
	}
	std::cout << sangdae_A << ' ' << meet_A_score;

	return 0;
}