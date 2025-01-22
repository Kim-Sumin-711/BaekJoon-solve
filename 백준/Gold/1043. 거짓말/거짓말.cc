#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

void set_know_people(std::unordered_set<short>& know_people, int cnt) {
	short tmp=0;
	while (cnt--) {
		std::cin >> tmp;
		know_people.insert(tmp);
	}
}

void set_party_vec(std::vector<std::vector<short>>& party_vec) {
	int goer_cnt=0;
	short tmp = 0;
	for (std::vector<short>& party : party_vec) {
		std::cin >> goer_cnt;
		while (goer_cnt--) {
			std::cin >> tmp;
			party.push_back(tmp);
		}
	}
}

int get_maximum_of_lie_cnt(std::unordered_set<short>& know_people, const std::vector<std::vector<short>>& party_vec,const int& people_cnt) {
	int res = 0;
	std::queue<short> person_qu;
	std::vector<bool> know(people_cnt + 1, false);
	for (short elem : know_people) {
		person_qu.push(elem);
		know[elem] = true;
	}
	while (person_qu.size() != 0) {
		short now = person_qu.front();
		person_qu.pop();
		for (const std::vector<short>& party : party_vec) {
			bool find_know_person = false;
			for (const short& person : party) {
				if (know_people.find(person) != know_people.end()) {
					find_know_person = true;
					break;
				}
			}
			if (find_know_person) {
				for (const short& person : party) {
					if (!know[person]) {
						know[person] = true;
						person_qu.push(person);
						know_people.insert(person);
					}
				}
			}
		}
	}
	for (const std::vector<short>& party : party_vec) {
		bool lie_able = true;
		for (const short& person : party) {
			if (know_people.find(person) != know_people.end()) {
				lie_able = false;
				break;
			}
		}
		if (lie_able)
			res++;
	}
	return res;
}

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int people_cnt, party_cnt;
	std::cin >> people_cnt >> party_cnt;
	int know_people_cnt;
	std::cin >> know_people_cnt;
	std::unordered_set<short> know_people;
	set_know_people(know_people, know_people_cnt);
	std::vector<std::vector<short>> party_vec(party_cnt);
	set_party_vec(party_vec);
	if (know_people_cnt == people_cnt)
		std::cout << 0;
	else if (know_people_cnt == 0)
		std::cout << party_cnt;
	else 
		std::cout << get_maximum_of_lie_cnt(know_people, party_vec, people_cnt);
	return 0;
}