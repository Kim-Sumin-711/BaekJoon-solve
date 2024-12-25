#include<iostream>
#include<stack>
#include<vector>

//if failed return false if not true
bool create_num(std::stack<int>& num_stack,int& now, const int& n, const int& target,std::vector<short int>& res) {
	for (int i = now; i < n + 2; i++) {
		if (target == i) {
			res.push_back(1);
			res.push_back(0);
			now = i+1;
			return true;
		}
		else if (target < i) {

			if (num_stack.size() == 0)
				return false;

			if (num_stack.top() != target)
				return false;

			else {
				num_stack.pop();
				now = i;
				res.push_back(0);
				return true;
			}
		}
		else {
			res.push_back(1);
			num_stack.push(i);
			continue;
		}
	}
	
}

void print_result(const std::vector<short int>& res) {
	for (const short int& result : res) {
		if (result)
			std::cout << "+\n";
		else
			std::cout << "-\n";
	}
}

void sol(const int& n) {
	std::stack<int> num_stack;
	std::vector<short int> res;
	std::vector<int> targets;
	//push : 1, pop : 0
	bool failed = false;
	int target,now_index=1;
	for (int i = 0; i < n; i++) {
		std::cin >> target;
		if (target > n || target < 1)
			failed = true;
		targets.push_back(target);
	}

	if (failed)
		std::cout << "No\n";
	else {
		for (const int& elem : targets) {
			failed = !create_num(num_stack, now_index, n, elem, res);
			if (failed) {
				std::cout << "NO\n";
				break;
			}
		}
		if (!failed)
			print_result(res);
	}
}

int main(void) {
	int n;
	std::cin >> n;
	sol(n);
	return 0;
}