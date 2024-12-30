//reference : https://baehoon.tistory.com/49
//first try : 마지막 골인지점은 무조건 밟으므로 골인지점부터 내려오는 방법으로 구현하려 시도
//second try : 처음 부분부터 시작하는데, now에서 4개 위 지점까지 가져와서 가능한 경로를
//모두 보고, 그 중 최대를 찾아보는 방식. 최대경로를 찾으면 무조건 지나야 하는 다음 지점으로 now를
//옮기기. 그러나 조건문 범벅이 되어 실패.
//third try : reference를 읽고, n번째 계단에 오르기 위한 점화식을 활용하자는 아이디어를 얻음.
//N번째 계단을 밟는다면, N-2번째 계단을 밟고 올라오든, N-3번째 밟고, N-1밟고 올라오든 둘 중 하나.
//그러니 N-2번째, N-3번째 계단을 밟았다고 했을때 최대 점수를 dp로 처리해서 둘 중 어떤게 더 최대인지
//판별하자.

#include<iostream>
#include<vector>

int main(void) {
	int stair_cnt;
	std::cin >> stair_cnt;
	std::vector<int>dp(stair_cnt+1), stair(stair_cnt+1);
	stair[0] = 0;
	for (int i = 1; i <= stair_cnt; i++)
		std::cin >> stair[i];
	//test_case 에 계단의 개수가 0이 있다는 소문이 있음.
	if (stair_cnt == 0) {
		std::cout << 0;
		return 0;
	}
	else if (stair_cnt == 1) {
		std::cout << stair[1];
		return 0;
	}

	else if (stair_cnt == 2) {
		std::cout << stair[1] + stair[2];
		return 0;
	}
	else if (stair_cnt == 3) {
		if (stair[1] > stair[2])
			std::cout << stair[1] + stair[3];
		else
			std::cout << stair[2] + stair[3];
		return 0;
	}


	//set dp
	dp[1] = stair[1];
	dp[2] = dp[1] + stair[2];

	if (stair[1] > stair[2])
		dp[3] = stair[1]+stair[3];
	else
		dp[3] = stair[2]+stair[3];


	//go loop
	int root1, root2;
	for (int i = 4; i <= stair_cnt; i++) {
		root1 = dp[i - 2] + stair[i];
		root2 = dp[i - 3] + stair[i - 1] + stair[i];
		if (root1 > root2)
			dp[i] = root1;
		else
			dp[i] = root2;
	}
	std::cout << dp[stair_cnt];
	return 0;
}
