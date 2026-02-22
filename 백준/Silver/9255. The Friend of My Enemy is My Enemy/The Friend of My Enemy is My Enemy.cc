#include<iostream>
#include<vector>
#include<algorithm>

bool find(const std::vector<short>& vec, short wanted) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == wanted) return true;
	}
	return false;
}

int main(void) {
	int tc; std::cin >> tc;
	for(int dt_num = 1 ; dt_num < tc+1; dt_num++) {
		int people_cnt, relationship_cnt; std::cin >> people_cnt >> relationship_cnt;
		std::vector<std::vector<short>> friends(people_cnt+1,std::vector<short>(0));
		while (relationship_cnt--) {
			short p1, p2; std::cin >> p1 >> p2;
			if(find(friends[p1], p2) == false) 
				friends[p1].push_back(p2);
			if(find(friends[p2], p1) == false)
				friends[p2].push_back(p1);
		}
		short suspicious; std::cin >> suspicious;
		std::sort(friends[suspicious].begin(), friends[suspicious].end());
		std::cout << "Data Set " << dt_num << ":\n";
		for (short ans : friends[suspicious]) {
			std::cout << ans << ' ';
		}
		std::cout << "\n\n";
	}
	return 0;
}