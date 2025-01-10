#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
int main(void)
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int test;
	std::cin >> test;
	std::string num;
	for (int i = 1; i < test + 1; i++) {
		std::cin >> num;
		std::cout << "Case #" << i << ": ";
		bool find = std::next_permutation(num.begin(), num.end());
		if (find)
			std::cout << num << "\n";
		else {
			std::sort(num.begin(), num.end());
			if (num[0] != '0')
				std::cout << num[0] << '0' << num.substr(1,num.size()-1) << "\n";
			else {
				for (int j = 1; j < num.size(); j++)
					if (num[j] != '0') {
						std::swap(num[0], num[j]);
						std::cout << num[0] << '0' << num.substr(1, num.size() - 1) << "\n";
						break;
					}
			}
		}
	}
	return 0;
}