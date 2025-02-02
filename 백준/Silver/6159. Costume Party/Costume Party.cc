#include<iostream>
#include<vector>
#include<algorithm>

//값을 받고, 오름차순 정렬을 한다. 투포인터 알고리즘을 사용하기 위함.
void set_cows(std::vector<int>& cows) {
	for (int& cow : cows)
		std::cin >> cow;
	std::sort(cows.begin(), cows.end());
}

//cows가 오름차순 정렬이 되었다고 가정하고 시작.
int get_fits_pair_of_cows_cnt(const std::vector<int>& cows, const int& costume_size) {
	int cow_pair_cnt = 0;
	int lpt = 0, rpt = (int)cows.size()-1;
	while (lpt < rpt) {
		int sum = cows[lpt] + cows[rpt];
		if (sum <= costume_size) {
			//합이 목표보다 작거나 같은 상태.
			//rpt가 왼쪽으로 다가갈 수 있는 모든 칸은 목표보다 작거나 같을 것이다. (벡터가 오름차순이니 rpt를 왼쪽으로 옮기면 합이 작아짐)
			//그래서 rpt-lpt만큼 정답값에 더해주고, lpt를 한칸 오른쪽으로 옮긴 후 loop를 돈다.
			//lpt를 오른쪽으로 옮기면 합이 커진다. (벡터가 오름차순이니까)
			//rpt는 만지지 않는다. 이전 lpt와의 합이 너무커서 여기까지 온건데 lpt를 오른쪽으로 옮긴 후에 다시 rpt보다 오른쪽을 고려한다면
			//했던짓을 또 하는 것이다.
			cow_pair_cnt += rpt - lpt;
			lpt++;
		}
		else if (sum > costume_size) {
			//합이 목표보다 더 큰 상태.
			//더 크니까 lpt를 유지, rpt를 왼쪽으로 옮긴다.
			rpt--;
		}
	}
	return cow_pair_cnt;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int cow_cnt, costume_size;
	std::cin >> cow_cnt >> costume_size;
	std::vector<int> cows(cow_cnt);
	set_cows(cows);
	std::cout << get_fits_pair_of_cows_cnt(cows, costume_size);
	return 0;
}