#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>

int main(void) {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int girl_group_cnt, problem_cnt;
	std::cin >> girl_group_cnt >> problem_cnt;
	std::unordered_map<std::string, std::vector<std::string>> girls_grouped_by_the_group_name;
	std::unordered_map<std::string, std::string> girls_and_group_names;
	
	//set maps
	std::string group_name, member_name;
	int members_cnt;
	while (girl_group_cnt--) {
		std::cin >> group_name;
		std::cin >> members_cnt;
		while (members_cnt--) {
			std::cin >> member_name;
			girls_grouped_by_the_group_name[group_name].push_back(member_name);
			girls_and_group_names[member_name] = group_name;
		}
		std::sort(girls_grouped_by_the_group_name[group_name].begin(), girls_grouped_by_the_group_name[group_name].end());
	}

	//problems
	std::string problem;
	int problem_type;
	while (problem_cnt--) {
		std::cin >> problem;
		std::cin >> problem_type;
		if (problem_type == 0) {
			for (const std::string members : girls_grouped_by_the_group_name[problem])
				std::cout << members << "\n";
		}
		else {
			std::cout << girls_and_group_names[problem] << "\n";
		}
	}
	return 0;
}