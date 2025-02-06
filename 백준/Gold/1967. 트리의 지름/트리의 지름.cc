#include<iostream>
#include<vector>

//10305019번 제출 참고해서 DFS풀이를 나타내보았다.

int node_cnt=0;
//vector의 index는 시작지점, pair.first는 도착하는 지점, second는 그 사이의 거리.
std::vector<std::vector<std::pair<int, int>>> graph(10001);
//최대 거리를 저장할 곳과 두번째로 dfs를 사용할 때 시작할 지점을 전역변수로 저장.
int max_dis = 0, one_point = 0;

//now는 시작 지점. passed 는 바로 전 단계에서 지났던 지점. dis는 현재까지 이동한 거리.
void dfs(int now, int passed, int dis=0) {
	//다음으로 갈 곳 있으면 재귀돌고 아니면 이 for문은 스킵되겠다.
	for (const std::pair<int, int>& route : graph[now]) {
		//전에서 왔던 곳을 중복해서 가고싶지는 않음.
		if(route.first != passed)
			dfs(route.first, now, dis + route.second);
	}
	//만일 최대 거리보다 더 멀리 왔으면 갱신하고 현재 노드를 one_point에 저장함.
	//첫번째로 1부터 가장 먼 노드 찾을때 그 노드를 one_point에 저장하고
	//다음으로 이 함수를 돌릴때 now에 넣기 위함.
	if (max_dis < dis) {
		max_dis = dis;
		one_point = now;
	}
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	std::cin >> node_cnt;
	int start, goal, cost;
	//setup graph
	while (--node_cnt) {
		std::cin >> start >> goal >> cost;
		graph[start].push_back(std::make_pair(goal, cost));
		graph[goal].push_back(std::make_pair(start, cost));
	}
	//1으로부터 가장 먼 노드의 번호를 one_point에 저장한다.
	dfs(1, 1);
	//one_point로부터 가장 먼 노드의 번호를 저장함과 동시에 지름을 max_dis에 저장.
	dfs(one_point, one_point);
	std::cout << max_dis;
	return 0;
}