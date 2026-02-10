#include<iostream>
int main(void) {
	int main_branch, R; std::cin >> main_branch >> R;
	int total_len = 0, branch_cnt = 2;
	main_branch *= R;
	main_branch /= 100; 
	while (main_branch > 5) {
		total_len += branch_cnt * main_branch;
		branch_cnt *= 2; 
		main_branch *= R;
		main_branch /= 100;
	}
	std::cout << total_len;
	return 0;
}